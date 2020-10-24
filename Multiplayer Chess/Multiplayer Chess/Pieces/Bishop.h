#pragma once
#include "IPiece.h"
#include <utility>

using namespace std;

class Bishop : public IPiece {
private:
	Piece type = Piece::Bishop;

public:
	Bishop(Color c = Color::None);

	Piece getType();

	vector<pair<char, char>> getMoves(pair<char, char>, vector<vector<IPiece*>> board);
};

