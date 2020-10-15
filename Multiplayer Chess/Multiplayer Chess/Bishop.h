#pragma once
#include "IPiece.h"

class Bishop:public IPiece {
	vector <pair<char, char>> getMoves(pair<char, char>);
};

