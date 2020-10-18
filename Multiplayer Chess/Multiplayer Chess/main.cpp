#include <SFML/Graphics.hpp>
#include "Pieces/IPiece.h"
#include "Client.h"
#include "Server.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 750), "SFML works!");
    
    char i;
    std::cin >> i;
    if (i == 'c') {
        Client c;
        std::cout << c.receive() << std::endl;
        c.send("bye", 3);
    }
    else if (i == 's') {
        Server s;
        s.send("hello", 5);
        std::cout << s.receive() << std::endl;
    }

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