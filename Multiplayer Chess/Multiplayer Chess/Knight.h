#pragma once
#include "IPiece.h"
#include <utility>

class Knight:public IPiece {
	vector <pair<char, char>> getMoves(pair<char, char>);
};

