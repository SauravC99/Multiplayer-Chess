#include "IPiece.h"

IPiece::IPiece() {
	color = Color::None;
}

IPiece::IPiece(Color a) {
	color = a;
}

Color IPiece::getColor() {
	return color;
}