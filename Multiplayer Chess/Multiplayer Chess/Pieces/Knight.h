#pragma once
#include "IPiece.h"
#include <utility>

class Knight:public IPiece {
private:
	Piece type = Piece::Knight;

public:
	Knight();

	Piece getType();

	vector <pair<char, char>> getMoves(pair<char, char>);
};

