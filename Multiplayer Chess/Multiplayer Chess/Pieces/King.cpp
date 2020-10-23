#include "King.h"

King::King() {
	type = Piece::King;
}

Piece King::getType() {
	return type;
}

vector<pair<char, char>> King::getMoves(pair<char, char>) {
	return vector<pair<char, char>>();
}