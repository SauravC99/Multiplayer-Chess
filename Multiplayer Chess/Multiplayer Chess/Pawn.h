#pragma once
#include "IPiece.h"

class Pawn:public IPiece {
	vector <pair<char, char>> getMoves(pair<char, char>);
};

