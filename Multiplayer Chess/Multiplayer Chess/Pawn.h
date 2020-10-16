#pragma once
#include "IPiece.h"
#include <utility>

class Pawn:public IPiece {
	vector <pair<char, char>> getMoves(pair<char, char>);
};

