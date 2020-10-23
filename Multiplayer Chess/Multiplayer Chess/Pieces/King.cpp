#include "King.h"

King::King(Color c) {
	type = Piece::King;
	color = c;
}

Piece King::getType() {
	return type;
}

vector<pair<char, char>> King::getMoves(pair<char, char> pos) {
	vector<pair<char, char>> moves;
	char rank = pos.first, file = pos.second;
	//forwards
	if (onBoard(rank+1, file-1)) moves.push_back(make_pair(rank+1, file-1));
	if (onBoard(rank+1, file  )) moves.push_back(make_pair(rank+1, file  ));
	if (onBoard(rank+1, file+1)) moves.push_back(make_pair(rank+1, file+1));
	//backwards
	if (onBoard(rank-1, file-1)) moves.push_back(make_pair(rank-1, file-1));
	if (onBoard(rank-1, file  )) moves.push_back(make_pair(rank-1, file  ));
	if (onBoard(rank-1, file+1)) moves.push_back(make_pair(rank-1, file+1));
	//sideways
	if (onBoard(rank, file-1)) moves.push_back(make_pair(rank, file-1));
	if (onBoard(rank, file+1)) moves.push_back(make_pair(rank, file+1));
	return moves;
}