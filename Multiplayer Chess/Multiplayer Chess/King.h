#pragma once
#include "IPiece.h"
#include <utility>

class King:public IPiece {
private:
	Piece type = Piece::King;

public:
	King();

	Piece getType();

	vector <pair<char, char>> getMoves(pair<char, char>);
};

