#pragma once
#include <vector>
#include <utility>

using namespace std;

enum class Color {White, Black, None};
enum class Piece {Pawn, Knight, Rook, Bishop, Queen, King};

class IPiece {
private:
	Color color;
	Piece type;

public:
	IPiece();
	IPiece(Color a);

	Color getColor();
	Piece getType();

	virtual vector<pair<char, char>> getMoves(pair<char, char>) = 0;
};