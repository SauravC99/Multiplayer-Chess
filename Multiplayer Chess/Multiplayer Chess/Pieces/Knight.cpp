#include "Knight.h"

using namespace std;

Knight::Knight(Color c) {
	type = Piece::Knight;
	color = c;
}

Piece Knight::getType() {
	return type;
}

vector<pair<char, char>> Knight::getMoves(pair<char, char> pos, vector<vector<IPiece*>> board) {
	vector<pair<char, char>> moves;
	char rank = pos.first, file = pos.second;
	//right
	if (onBoard(rank + 1, file + 2)) moves.push_back(make_pair(rank + 1, file + 2));
	if (onBoard(rank - 1, file + 2)) moves.push_back(make_pair(rank - 1, file + 2));

	//left
	if (onBoard(rank + 1, file - 2)) moves.push_back(make_pair(rank + 1, file - 2));
	if (onBoard(rank - 1, file - 2)) moves.push_back(make_pair(rank - 1, file - 2));

	//up
	if (onBoard(rank + 2, file + 1)) moves.push_back(make_pair(rank + 2, file + 1));
	if (onBoard(rank + 2, file - 1)) moves.push_back(make_pair(rank + 2, file - 1));

	//down
	if (onBoard(rank - 2, file + 1)) moves.push_back(make_pair(rank - 2, file + 1));
	if (onBoard(rank - 2, file - 1)) moves.push_back(make_pair(rank - 2, file - 1));

	return moves;
}