#pragma once
#include <vector>
#include <utility>

using namespace std;

enum class Color {White, Black, None};
enum class Piece {Pawn, Knight, Rook, Bishop, Queen, King};

class IPiece {
private:
	Piece type;

public:
	Color color;

public:
	IPiece();
	IPiece(Color a);

	Color getColor();

	virtual Piece getType() = 0;
	virtual vector<pair<char, char>> getMoves(pair<char, char>) = 0;
	
	bool onBoard(char rank, char file);
};