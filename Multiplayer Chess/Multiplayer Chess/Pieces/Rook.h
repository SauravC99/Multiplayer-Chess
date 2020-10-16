#pragma once
#include "IPiece.h"
#include <utility>

using namespace std;

class Rook:public IPiece {
	vector<pair<char, char>> getMoves(pair<char, char>);
};

