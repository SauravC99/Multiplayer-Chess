#pragma once
//#include "Board.h"
#include <SFML/Graphics.hpp>
#include "Pieces/IPiece.h"
#include "ChessRenderer.h"
#include "Board.h"
#include <utility>

class Chess
{
private:
	Board board;
	Color currentTurn;
	ChessRenderer renderer;
	sf::RenderWindow* window;
	sf::Texture boardTexture;
	sf::Sprite boardSprite;

	void render();

public:
	Chess();
	~Chess();

	bool move(std::pair<char, char> source, std::pair<char, char> destination);
	void play();
};

