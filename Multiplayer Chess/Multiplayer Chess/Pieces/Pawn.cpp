#include "Pawn.h"

Pawn::Pawn(Color c) {
	type = Piece::Pawn;
	color = c;
}

Piece Pawn::getType() {
	return type;
}

vector<pair<char, char>> Pawn::getMoves(pair<char, char> pos, vector<vector<IPiece*>> board) {
	vector<pair<char, char>> moves;
	char rank = pos.first, file = pos.second;

	if (color == Color::White) {
		//white pawn moves
		if (rank == '2') {
			if (board[rankToCoord(rank+1)][fileToCoord(file)] == nullptr and
				board[rankToCoord(rank+2)][fileToCoord(file)] == nullptr)
				 moves.push_back(make_pair(rank+2, file));
		}
		if (onBoard(rank+1, file-1) and board[rankToCoord(rank+1)][fileToCoord(file-1)] != nullptr) 
			moves.push_back(make_pair(rank+1, file-1));
		if (onBoard(rank+1, file  ) and board[rankToCoord(rank+1)][fileToCoord(file)]   == nullptr)
			moves.push_back(make_pair(rank+1, file  ));
		if (onBoard(rank+1, file+1) and board[rankToCoord(rank+1)][fileToCoord(file+1)] != nullptr)
			moves.push_back(make_pair(rank+1, file+1));
	}
	else {
		//black pawn moves
		if (rank == '7') {
			if(board[rankToCoord(rank-1)][fileToCoord(file)] == nullptr and
			   board[rankToCoord(rank-2)][fileToCoord(file)] == nullptr)
				moves.push_back(make_pair(rank-2, file));
		}
		if (onBoard(rank-1, file-1) and board[rankToCoord(rank-1)][fileToCoord(file-1)] != nullptr)
			moves.push_back(make_pair(rank-1, file-1));
		if (onBoard(rank-1, file  ) and board[rankToCoord(rank-1)][fileToCoord(file)]   == nullptr)
			moves.push_back(make_pair(rank-1, file  ));
		if (onBoard(rank-1, file+1) and board[rankToCoord(rank-1)][fileToCoord(file+1)] != nullptr) 
			moves.push_back(make_pair(rank-1, file+1));
	}

	return moves;
}