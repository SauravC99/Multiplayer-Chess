#pragma once
#include "IPiece.h"
#include <utility>

using namespace std;

class Pawn:public IPiece {
private:
	Piece type = Piece::Pawn;

public:
	Pawn();

	Piece getType();

	vector<pair<char, char>> getMoves(pair<char, char>);
};

