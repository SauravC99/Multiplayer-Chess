#pragma once
#include "Pieces/IPiece.h"
#include "Pieces/Pawn.h"
#include "Pieces/Bishop.h"
#include "Pieces/Knight.h"
#include "Pieces/Rook.h"
#include "Pieces/King.h"
#include "Pieces/Queen.h"
#include <utility>

class Board
{
private:
	std::vector<std::vector<IPiece*>> board;

public:
	Board();

	void move(std::pair<char, char> source, std::pair<char, char> destination);
	IPiece* get(std::pair<char, char> position);
	std::vector<std::vector<IPiece*>> getBoard();

	static std::pair<int, int> convert(std::pair<char, char>);
};

