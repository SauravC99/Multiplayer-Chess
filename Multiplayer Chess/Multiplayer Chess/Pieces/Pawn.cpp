#include "Pawn.h"

Pawn::Pawn() {
	type = Piece::Pawn;
}

Piece Pawn::getType() {
	return type;
}

vector<pair<char, char>> Pawn::getMoves(pair<char, char>) {
	return vector<pair<char, char>>();
}