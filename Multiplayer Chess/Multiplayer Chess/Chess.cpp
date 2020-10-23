#include "Chess.h"
#include <SFML/Graphics.hpp>

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
    for (char rank = 8; rank >= 1; rank--) {
        for (char file = 'A'; file <= 'H'; file++) {
            IPiece* temp = board.get(std::make_pair(rank, file));
            if(temp->getName() == "King")
        }
    }
    window->display();
}

bool Chess::move(std::pair<char, char> src, std::pair<char, char> dest) {
    //run the render cycle everytime a new piece is moved
    render();
	return true;
}

void Chess::play() {
    render();
    //poll window for events
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
    }
}