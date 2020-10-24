#include "Chess.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "Networking/Client.h"
#include "Networking/Server.h"

#define SQUARE_SIZE 100

//helper function prototype
std::pair<char, char> clickToPos(int x, int y);

Chess::Chess() {
	currentTurn = Color::White;

    //initialize window
    window = new sf::RenderWindow(sf::VideoMode(800,800), "Multiplayer Chess");
    
    //setup background image
    boardTexture.loadFromFile("board.png");
    boardSprite.setTexture(boardTexture);
}

Chess::~Chess() {
    delete window;
}

void Chess::render() {
    window->clear();
    window->draw(boardSprite);
    for (char rank = '8'; rank >= '1'; rank--) {
        for (char file = 'A'; file <= 'H'; file++) {
            
            IPiece* temp = board.get(std::make_pair(rank, file));
            if (temp != nullptr) {
                sf::Vector2f pos((file - 'A') * SQUARE_SIZE, -1 * (rank - '8') * SQUARE_SIZE);

                switch (temp->getType()) {
                case Piece::King  : renderer.draw(*window, cr::Piece::King  , temp->getColor() == Color::Black, pos); break;
                case Piece::Queen : renderer.draw(*window, cr::Piece::Queen , temp->getColor() == Color::Black, pos); break;
                case Piece::Rook  : renderer.draw(*window, cr::Piece::Rook  , temp->getColor() == Color::Black, pos); break;
                case Piece::Bishop: renderer.draw(*window, cr::Piece::Bishop, temp->getColor() == Color::Black, pos); break;
                case Piece::Knight: renderer.draw(*window, cr::Piece::Knight, temp->getColor() == Color::Black, pos); break;
                case Piece::Pawn  : renderer.draw(*window, cr::Piece::Pawn  , temp->getColor() == Color::Black, pos); break;
                }
            }
        }
    }
    window->display();
}

bool Chess::move(std::pair<char, char> src, std::pair<char, char> dest) {
    if (board.get(src) == nullptr) return false;
    if (board.get(src)->getColor() != currentTurn) return false;

    //see if move is at least valid for the selected piece
    std::vector<std::pair<char, char>> potentialMoves;
    potentialMoves = board.get(src)->getMoves(src, board.getBoard());

    bool check1 = false;
    for (std::pair<char, char> move : potentialMoves) {
        if (move.first == dest.first and move.second == dest.second)
            check1 = true;
    }

    if (!check1) return false;

    //cant land on piece of same color
    bool check2 = false;
    if (board.get(dest) != nullptr) {
        if (board.get(src)->getColor() != board.get(dest)->getColor())
            check2 = true;
    }
    else
        check2 = true;

    if (!check2) return false;

    //special cases
    //king moves

    //pawn moves


    //run the render cycle everytime a new piece is moved
    board.move(src, dest);
    render();
	return true;
}

void Chess::play() {
    //draw initial board state
    render();
    
    //Networking
    Socket* socket = nullptr;

    std::string role;
    std::cout << "Enter s for server or c for client: ";
    std::getline(std::cin, role);
    
    if (role == "s") socket = new Server(25565);
    else {
        std::string ip;
        std::cout << "Insert ip address of server: ";
        std::getline(std::cin, ip);
        try {
            socket = new Client(ip, 25565);
        }
        catch (const char* msg) {
            std::cout << msg << std::endl;
            window->close();
            return;
        }
    }

    std::string previousMove;

    //game logic
    std::pair<char, char> src, dst;
    int counter = 0;
    bool myTurn = false;

    //handle initial move
    if (role == "s") {
        myTurn = true;
    }

    //poll window for events
    while (window->isOpen())
    {
        //handle initial move
        if (!myTurn) {
            //std::cout << role << " receiving" << std::endl;
            if (socket->receive(previousMove)) {
                makePrevMove(previousMove);
                nextPlayer();
                myTurn = true;
            }
        }
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            if (myTurn) {
                if (event.type == sf::Event::MouseButtonReleased) {
                    if (counter == 1) {
                        dst = clickToPos(event.mouseButton.x, event.mouseButton.y);
                        if (move(src, dst)) {
                            nextPlayer();
                            char data[4];
                            data[0] = src.first; data[1] = src.second;
                            data[2] = dst.first; data[3] = dst.second;
                            std::cout << role << " sending" << std::endl;
                            socket->send(data, 4);
                            myTurn = false;
                        }
                    }
                    else {
                        counter = 0;
                        src = clickToPos(event.mouseButton.x, event.mouseButton.y);
                    }
                    counter++;
                }
            }
        }
        render();
    }
}

void Chess::nextPlayer() {
    if (currentTurn == Color::White) currentTurn = Color::Black;
    else currentTurn = Color::White;
}

void Chess::makePrevMove(std::string previousMove) {
    move(std::make_pair(previousMove[0], previousMove[1]),
         std::make_pair(previousMove[2], previousMove[3]));
}

std::pair<char, char> clickToPos(int x, int y) {
    x /= SQUARE_SIZE;
    y /= SQUARE_SIZE;
    x += 'A';
    y = -1 * (y - '8');
    if      (x < 'A') x = 'A';
    else if (x > 'H') x = 'H';
    if (y < '1') y = '1';
    else if (y > '8') y = '8';
    return std::make_pair(y, x);
}