#pragma once
#include "IPiece.h"
#include <utility>

using namespace std;

class Knight:public IPiece {
private:
	Piece type = Piece::Knight;

public:
	Knight();

	Piece getType();

	vector<pair<char, char>> getMoves(pair<char, char>);
};

