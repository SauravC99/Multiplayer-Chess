#include "Bishop.h"

using namespace std;

Bishop::Bishop(Color c) {
	type = Piece::Bishop;
	color = c;
}

Piece Bishop::getType() {
	return type;
}

vector<pair<char, char>> Bishop::getMoves(pair<char, char> pos) {
	vector<pair<char, char>> moves;
	char rank = pos.first, file = pos.second;
	//up and to the left
	rank++; file--;
	while (onBoard(rank, file)) {
		moves.push_back(make_pair(rank, file));
		rank++; file--;
	}
	rank = pos.first, file = pos.second;

	//up and to the right
	rank++; file++;
	while (onBoard(rank, file)) {
		moves.push_back(make_pair(rank, file));
		rank++; file++;
	}
	rank = pos.first, file = pos.second;

	//down and to the left
	rank--; file--;
	while (onBoard(rank, file)) {
		moves.push_back(make_pair(rank, file));
		rank--; file--;
	}
	rank = pos.first, file = pos.second;

	//down and to the right
	rank--; file++;
	while (onBoard(rank, file)) {
		moves.push_back(make_pair(rank, file));
		rank--; file++;
	}

	return moves;
}