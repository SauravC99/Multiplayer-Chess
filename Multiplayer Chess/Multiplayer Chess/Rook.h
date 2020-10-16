#pragma once
#include "IPiece.h"
#include <utility>

class Rook:public IPiece {
	vector <pair<char, char>> getMoves(pair<char, char>);
};

