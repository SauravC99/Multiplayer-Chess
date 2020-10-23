#include "Queen.h"

Queen::Queen() {
	type = Piece::Queen;
}

Piece Queen::getType() {
	return type;
}

vector<pair<char, char>> Queen::getMoves(pair<char, char>) {
	return vector<pair<char, char>>();
}