#include <SFML/Graphics.hpp>
#include "Pieces/IPiece.h"
#include "Client.h"
#include "Server.h"
#include <iostream>
#include "ChessRenderer.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 750), "SFML works!");

    ChessRenderer cr;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        cr.draw(window);
        window.display();
    }

    return 0;
}