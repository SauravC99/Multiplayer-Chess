#pragma once
#include "IPiece.h"

class King:public IPiece {
	vector <pair<char, char>> getMoves(pair<char, char>);
};

