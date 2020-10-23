#pragma once
#include "IPiece.h"
#include <utility>

using namespace std;

class King:public IPiece {
private:
	Piece type = Piece::King;

public:
	King(Color c = Color::None);

	Piece getType();

	vector<pair<char, char>> getMoves(pair<char, char>);
};

