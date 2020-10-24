#pragma once
#include "IPiece.h"
#include <utility>

using namespace std;

class Queen:public IPiece {
private:
	Piece type = Piece::Queen;

public:
	Queen(Color c = Color::None);

	Piece getType();

	vector <pair<char, char>> getMoves(pair<char, char>, vector<vector<IPiece*>> board);
};

