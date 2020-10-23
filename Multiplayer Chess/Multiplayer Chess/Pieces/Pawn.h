#pragma once
#include "IPiece.h"
#include <utility>

using namespace std;

class Pawn : public IPiece {
private:
	Piece type = Piece::Pawn;

public:
	Pawn(Color color = Color::None);

	Piece getType();

	vector<pair<char, char>> getMoves(pair<char, char>);
};

