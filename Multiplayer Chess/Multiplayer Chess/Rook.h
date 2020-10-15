#pragma once
#include "IPiece.h"

class Rook:public IPiece {
	vector <pair<char, char>> getMoves(pair<char, char>);
};

