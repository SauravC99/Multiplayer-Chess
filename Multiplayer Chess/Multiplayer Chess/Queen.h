#pragma once
#include "IPiece.h"

class Queen:public IPiece {
	vector <pair<char, char>> getMoves(pair<char, char>);
};

