#include <SFML/Graphics.hpp>
#include "Pieces/IPiece.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 750), "SFML works!");
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}