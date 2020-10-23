#pragma once
#include "IPiece.h"
#include <utility>

using namespace std;

class Queen:public IPiece {
private:
	Piece type = Piece::Queen;

public:
	Queen();

	Piece getType();

	vector <pair<char, char>> getMoves(pair<char, char>);
};

