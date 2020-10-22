#include "Knight.h"

Knight::Knight() {
	type = Piece::Knight;
}

Piece Knight::getType() {
	return type;
}

vector <pair<char, char>> Knight::getMoves(pair<char, char>) {
	return vector<pair<char, char>>();
}