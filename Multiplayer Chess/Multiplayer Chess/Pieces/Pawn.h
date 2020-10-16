#pragma once
#include "IPiece.h"
#include <utility>

using namespace std;

class Pawn:public IPiece {
	vector<pair<char, char>> getMoves(pair<char, char>);
};

