#pragma once
#include "IPiece.h"
#include <utility>

using namespace std;

class Rook:public IPiece {
private:
	Piece type = Piece::Rook;

public:
	Rook();

	Piece getType();

	vector<pair<char, char>> getMoves(pair<char, char>);
};

