#include "Board.h"

Board::Board() {
	//size board to be 8x8
	board.resize(8);
	for (int i = 0; i < 8; i++) {
		board[i].resize(8);
	}

//add pieces
	//White	
	for (int i = 0; i < 8; i++) {
		board[6][i] = new Pawn(Color::White);
	}
	board[7][0] = new Rook(Color::White);
	board[7][1] = new Knight(Color::White);
	board[7][2] = new Bishop(Color::White);
	board[7][3] = new Queen(Color::White);
	board[7][4] = new King(Color::White);
	board[7][5] = new Bishop(Color::White);
	board[7][6] = new Knight(Color::White);
	board[7][7] = new Rook(Color::White);

	//Black
	for (int i = 0; i < 8; i++) {
		board[1][i] = new Pawn(Color::Black);
	}
	board[0][0] = new Rook(Color::Black);
	board[0][1] = new Knight(Color::Black);
	board[0][2] = new Bishop(Color::Black);
	board[0][3] = new Queen(Color::Black);
	board[0][4] = new King(Color::Black);
	board[0][5] = new Bishop(Color::Black);
	board[0][6] = new Knight(Color::Black);
	board[0][7] = new Rook(Color::Black);
}

void Board::move(std::pair<char, char> src, std::pair<char, char> dest) {
	std::pair<int, int> srcCoords  = convert(src),
	                    destCoords = convert(dest);

	delete board[destCoords.first][destCoords.second];
	board[destCoords.first][destCoords.second] = board[srcCoords.first][srcCoords.second];
	board[srcCoords.first][srcCoords.second] = nullptr;
}

IPiece* Board::get(std::pair<char, char> pos) {
	std::pair<int, int> coords = convert(pos);
	return board[coords.first][coords.second];
}

std::vector<std::vector<IPiece*>> Board::getBoard() {
	return board;
}

std::pair<int, int> Board::convert(std::pair<char, char> pos) {
	return std::make_pair(-1 * (pos.first - '8'), pos.second - 'A');
}