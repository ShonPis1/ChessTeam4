#pragma once
#include "nullPiece.h"
#include "King.h"
#include "Rook.h"

class Board
{
public:
	Board();
	~Board();

	void updateBoard(Coord start, Coord end);
	bool generalValidate(Coord start, Coord end);

protected:
	Piece _boardStatus[8][8];

private:
	bool _isWhitePlayer;
};