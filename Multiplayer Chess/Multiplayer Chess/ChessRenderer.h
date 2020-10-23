#pragma once
#include <SFML/Graphics.hpp>

namespace cr {
	enum class Piece { King, Queen, Rook, Bishop, Knight, Pawn };
}

class ChessRenderer
{
private:
	//Board board;
	sf::Texture spritesheet;
	sf::Sprite  sprites [12];

public:
	ChessRenderer();
	void draw(sf::RenderWindow& window, cr::Piece piece, bool isBlack, sf::Vector2f position);
};

