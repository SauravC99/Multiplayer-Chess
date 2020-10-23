#include "Queen.h"

Queen::Queen(Color c) {
	type = Piece::Queen;
	color = c;
}

Piece Queen::getType() {
	return type;
}

vector<pair<char, char>> Queen::getMoves(pair<char, char> pos) {
	vector<pair<char, char>> moves;
	char rank = pos.first, file = pos.second;

//Diagonals

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
	rank = pos.first, file = pos.second;



//Cardinal directions

	//up
	for (rank = pos.first + 1; rank < '9'; rank++) {
		if (onBoard(rank, pos.second)) moves.push_back(make_pair(rank, pos.second));
		else break;
	}
	//down
	for (rank = pos.first - 1; rank > '0'; rank--) {
		if (onBoard(rank, pos.second)) moves.push_back(make_pair(rank, pos.second));
		else break;
	}
	//left
	for (file = pos.second - 1; file >= 'A'; file--) {
		if (onBoard(pos.first, file)) moves.push_back(make_pair(pos.first, file));
		else break;
	}
	//right
	for (file = pos.second + 1; file <= 'H'; file++) {
		if (onBoard(pos.first, file)) moves.push_back(make_pair(pos.first, file));
		else break;
	}

	return moves;
}