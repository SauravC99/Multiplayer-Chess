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

bool IPiece::onBoard(char rank, char file) {
	return (rank > '8' or rank < '1' or file < 'A' or file > 'H') ? false : true;
}

int IPiece::rankToCoord(char rank) {
	return -1 * (rank - '8');
}

int IPiece::fileToCoord(char file) {
	return file - 'A';
}