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
	Color currentTurn = Color::White;
	ChessRenderer renderer;
	//Variables for the graphics
	sf::RenderWindow* window;
	sf::Texture boardTexture;
	sf::Sprite boardSprite;

//Helper functions
	//Draw all the pieces on the board
	void render();
	//Switches currentTurn from white to black and vice versa
	void nextPlayer();
	//helper for play(), makes the move described by previousMove variable
	void makePrevMove(std::string);

public:
	Chess();
	~Chess();

	//Move piece at source position to destination position, false if move is invalid
	bool move(std::pair<char, char> source, std::pair<char, char> destination);
	//main game loop
	void play();
};

