#include "ChessRenderer.h"

ChessRenderer::ChessRenderer() {
	if (!spritesheet.loadFromFile("chess pieces.png")) {
		throw "Could not load \"chess pieces.png\"";
	}
	spritesheet.setSmooth(true);

	sf::Vector2u textureSize = spritesheet.getSize();
	textureSize.x /= 6;
	textureSize.y /= 2;

	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 6; col++) {
			sf::IntRect bounds(textureSize.x * col, textureSize.y * row,
				               textureSize.x      , textureSize.y      );
			sprites[row * 6 + col].setTexture(spritesheet);
			sprites[row * 6 + col].setTextureRect(bounds);
			sprites[row * 6 + col].setScale(0.5f, 0.5f);
		}
	}
}

void ChessRenderer::draw(sf::RenderWindow& window, cr::Piece piece, bool isBlack, sf::Vector2f position) {
	int i;
	switch (piece) {
	case cr::Piece::King   :	  i = 6 * isBlack ;		 break;
	case cr::Piece::Queen  :	  i = 6 * isBlack + 1;	 break;
	case cr::Piece::Bishop :	  i = 6 * isBlack + 2;	 break;
	case cr::Piece::Knight :	  i = 6 * isBlack + 3;	 break;
	case cr::Piece::Rook   :	  i = 6 * isBlack + 4;	 break;
	case cr::Piece::Pawn   :	  i = 6 * isBlack + 5;	 break;
	default : return;
	}
	sprites[i].setPosition(position);
	window.draw(sprites[i]);
}
