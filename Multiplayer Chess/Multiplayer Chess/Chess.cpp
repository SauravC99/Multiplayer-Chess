#include "Chess.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "Networking/Client.h"
#include "Networking/Server.h"

#define SQUARE_SIZE 100

//helper function prototype
std::pair<char, char> clickToPos(int x, int y);

//Default Constructor
Chess::Chess() {
	currentTurn = Color::White;
    
    //setup background image
    boardTexture.loadFromFile("board.png");
    boardSprite.setTexture(boardTexture);
}

//Destructor
Chess::~Chess() {
    delete window;
}

//Draw all the pieces on the board
void Chess::render() {
    window->clear();
    window->draw(boardSprite);
    //for each rank(1-8) and file(A-H)
    for (char rank = '8'; rank >= '1'; rank--) {
        for (char file = 'A'; file <= 'H'; file++) {
            
            IPiece* temp = board.get(std::make_pair(rank, file));
            if (temp != nullptr) {
                //converts rank and file to window coordinates
                sf::Vector2f pos((file - 'A') * SQUARE_SIZE, -1 * (rank - '8') * SQUARE_SIZE);

                //Calls draw function with the proper piece type Ex. Piece::King should draw a King
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

//If a piece exists at src, then it moves it to dest
//function will not move the piece and return false 
//if the move is an invalid move
bool Chess::move(std::pair<char, char> src, std::pair<char, char> dest) {
    if (board.get(src) == nullptr) return false; //no piece at src position
    if (board.get(src)->getColor() != currentTurn) return false; //selected wrong colored piece

    //see if move is at least valid for the selected piece
    std::vector<std::pair<char, char>> potentialMoves;
    potentialMoves = board.get(src)->getMoves(src, board.getBoard());

    bool check1 = false;
    for (std::pair<char, char> move : potentialMoves) {
        if (move.first == dest.first and move.second == dest.second)
            check1 = true;
    }

    if (!check1) return false; //dest was not an element of the piece's possible moves

    //cant land on piece of same color
    bool check2 = false;
    if (board.get(dest) != nullptr) {
        if (board.get(src)->getColor() != board.get(dest)->getColor())
            check2 = true;
    }
    else
        check2 = true;

    if (!check2) return false; //attempted to land on piece of the same color


    //run the render cycle everytime a new piece is moved
    board.move(src, dest);
    render();
	return true;
}

void Chess::play() {
    //Networking
    Socket* socket = nullptr;

    //allow player to choose between being the server or client
    std::string role;
    std::cout << "Enter s for server or c for client: ";
    std::getline(std::cin, role);
    
    //setup server socket
    if (role == "s") {
        try {
            socket = new Server(25565);
        }
        catch (const char* msg) {
            std::cout << msg << std::endl;
            window->close();
            return;
        }
    }
    //setup client socket
    else {
        //ask for details of the desired server
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

    //create window
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "Multiplayer Chess");

//game logic
    std::string previousMove;
    std::pair<char, char> src, dst;
    int counter = 0;
    bool myTurn = false;

    //handle initial move, server goes first
    if (role == "s") {
        myTurn = true;
    }

    //poll window for events
    while (window->isOpen())
    {
        //if its not your turn then receive until opponent makes a move
        if (!myTurn) {
            if (socket->receive(previousMove)) {
                makePrevMove(previousMove);
                nextPlayer();
                myTurn = true;
            }
        }

        //Handle events
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();

            //Handle events only if it is your turn
            if (myTurn) {
                //Click Event
                if (event.type == sf::Event::MouseButtonReleased) {
                    //counter = 1 when its destination click
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
                    //counter = 0 signifies source click
                    else {
                        counter = 0;
                        src = clickToPos(event.mouseButton.x, event.mouseButton.y);
                        if (board.get(src) == nullptr or board.get(src)->getColor() != currentTurn)
                            counter--;
                    }
                    counter++;
                }
            }
        }
        render();
    }
}

//Switches currentTurn from white to black and vice versa
void Chess::nextPlayer() {
    if (currentTurn == Color::White) currentTurn = Color::Black;
    else currentTurn = Color::White;
}

//helper for play(), makes the move described by previousMove variable
void Chess::makePrevMove(std::string previousMove) {
    move(std::make_pair(previousMove[0], previousMove[1]),
         std::make_pair(previousMove[2], previousMove[3]));
}

//Convert click position to rank and file
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