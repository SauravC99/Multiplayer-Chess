#include "Pawn.h"

Pawn::Pawn(Color c) {
	type = Piece::Pawn;
	color = c;
}

Piece Pawn::getType() {
	return type;
}

vector<pair<char, char>> Pawn::getMoves(pair<char, char> pos) {
	vector<pair<char, char>> moves;
	char rank = pos.first, file = pos.second;

	if (color == Color::White) {
		//white pawn moves
		if (rank == 2) {
			moves.push_back(make_pair(rank + 2, file));
		}
		if (onBoard(rank+1, file-1)) moves.push_back(make_pair(rank+1, file-1));
		if (onBoard(rank+1, file  )) moves.push_back(make_pair(rank+1, file  ));
		if (onBoard(rank+1, file+1)) moves.push_back(make_pair(rank+1, file+1));
	}
	else {
		//black pawn moves
		if (rank == 7) {
			moves.push_back(make_pair(rank - 2, file));
		}
		if (onBoard(rank-1, file-1)) moves.push_back(make_pair(rank-1, file-1));
		if (onBoard(rank-1, file  )) moves.push_back(make_pair(rank-1, file  ));
		if (onBoard(rank-1, file+1)) moves.push_back(make_pair(rank-1, file+1));
	}

	return moves;
}