#include "Bishop.h"

using namespace std;

Bishop::Bishop() {
	type = Piece::Bishop;
}

Piece Bishop::getType() {
	return type;
}

vector<pair<char, char>> Bishop::getMoves(pair<char, char>) {
	return vector<pair<char, char>>();
}