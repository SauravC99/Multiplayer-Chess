#pragma once
#include <SFML/Graphics.hpp>

class ChessRenderer
{
private:
	//Board board;
	sf::Texture spritesheet;
	sf::Sprite  sprites [12];

public:
	ChessRenderer();
	void draw(sf::RenderWindow& window);
};

