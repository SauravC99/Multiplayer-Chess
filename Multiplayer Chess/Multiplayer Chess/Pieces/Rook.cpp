#include "Rook.h"

Rook::Rook(Color c) {
	type = Piece::Rook;
	color = c;
}

Piece Rook::getType() {
	return type;
}

vector<pair<char, char>> Rook::getMoves(pair<char, char> pos, vector<vector<IPiece*>> board) {
	vector<pair<char, char>> moves;

	//up
	for (char rank = pos.first+1; rank < '9'; rank++) {
		if (onBoard(rank, pos.second)) moves.push_back(make_pair(rank, pos.second));
		else break;

		if (board[rankToCoord(rank)][fileToCoord(pos.second)] != nullptr)
			break;
	}
	//down
	for (char rank = pos.first-1; rank > '0'; rank--) {
		if (onBoard(rank, pos.second)) moves.push_back(make_pair(rank, pos.second));
		else break;

		if (board[rankToCoord(rank)][fileToCoord(pos.second)] != nullptr)
			break;
	}
	//left
	for (char file = pos.second-1; file >= 'A'; file--) {
		if (onBoard(pos.first, file)) moves.push_back(make_pair(pos.first, file));
		else break;

		if (board[rankToCoord(pos.first)][fileToCoord(file)] != nullptr)
			break;
	}
	//right
	for (char file = pos.second+1; file <= 'H'; file++) {
		if (onBoard(pos.first, file)) moves.push_back(make_pair(pos.first, file));
		else break;

		if (board[rankToCoord(pos.first)][fileToCoord(file)] != nullptr)
			break;
	}
	return moves;
}