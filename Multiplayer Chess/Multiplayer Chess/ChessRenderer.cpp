#include "ChessRenderer.h"

ChessRenderer::ChessRenderer() {
	if (!spritesheet.loadFromFile("chess pieces.png")) {
		throw "Could not load \"chess pieces.png\"";
	}

	sf::Vector2u textureSize = spritesheet.getSize();
	textureSize.x /= 6;
	textureSize.y /= 2;

	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 6; col++) {
			sf::IntRect bounds(textureSize.x * col, textureSize.y * row,
				               textureSize.x      , textureSize.y      );
			sprites[row * 6 + col].setTexture(spritesheet);
			sprites[row * 6 + col].setTextureRect(bounds);
		}
	}
}

void ChessRenderer::draw(sf::RenderWindow& window, Piece piece, bool isWhite, sf::Vector2f position) {
	int i;
	switch (piece) {
	case Piece::King  :	  i = 6 * isWhite ;		 break;
	case Piece::Queen :	  i = 6 * isWhite + 1;	 break;
	case Piece::Bishop:	  i = 6 * isWhite + 2;	 break;
	case Piece::Knight:	  i = 6 * isWhite + 3;	 break;
	case Piece::Rook  :	  i = 6 * isWhite + 4;	 break;
	case Piece::Pawn  :	  i = 6 * isWhite + 5;	 break;
	}
	sprites[i].setPosition(position);
	window.draw(sprites[i]);
}
