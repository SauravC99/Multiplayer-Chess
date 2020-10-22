#include "Rook.h"

Rook::Rook() {
	type = Piece::Rook;
}

Piece Rook::getType() {
	return type;
}

vector <pair<char, char>> Rook::getMoves(pair<char, char>) {
	return vector<pair<char, char>>();
}