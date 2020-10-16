#pragma once
#include "IPiece.h"
#include <utility>

class King:public IPiece {
	vector <pair<char, char>> getMoves(pair<char, char>);
};

