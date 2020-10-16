#pragma once
#include "IPiece.h"
#include <utility>

using namespace std;

class Queen:public IPiece {
public:
	vector <pair<char, char>> getMoves(pair<char, char>);
};

