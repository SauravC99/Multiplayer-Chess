#pragma once
#include "IPiece.h"

class Knight:public IPiece {
	vector <pair<char, char>> getMoves(pair<char, char>);
};

