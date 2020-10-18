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
	sprites[7].setPosition(100.f, 100.f);
}

void ChessRenderer::draw(sf::RenderWindow& window) {
	window.draw(sprites[7]);
}
