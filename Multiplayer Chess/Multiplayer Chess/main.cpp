#include <SFML/Graphics.hpp>
#include <iostream>
#include "Chess.h"

#include "Pieces/Knight.h"
#include <utility>
int main()
{
    Knight b;
    for (pair<char, char> p : b.getMoves(std::make_pair('5', 'D'))) {
        std::cout << p.first << " " << p.second << std::endl;
    }
    Chess c;
    c.play();
    return 0;
}