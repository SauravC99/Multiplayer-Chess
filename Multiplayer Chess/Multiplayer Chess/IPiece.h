#pragma once
#include <vector>
#include <utility>

using namespace std;

enum class Color {White, Black, None};

class IPiece {
private:
	Color color;

public:
	IPiece();
	IPiece(Color a);

	Color getColor();

	virtual vector <pair<char, char>> getMoves(pair<char, char>) = 0;
};