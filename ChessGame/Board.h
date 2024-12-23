#pragma once
#include "NullPiece.h"
#include "King.h"
#include "Rook.h"

class Board
{
public:
	Board();
	~Board();

	void updateBoard(const Coord start, const Coord end);
	bool generalValidate(const Coord start, const Coord end);

protected:
	Piece _boardStatus[8][8];

private:
	bool _isWhitePlayer;
};