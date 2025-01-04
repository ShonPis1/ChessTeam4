#pragma once

#include <iostream>
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

class Board
{
public:
	Board();
	Board(const Board& other); //copy constructor
	~Board();

	/*updates the board status with a new move 
	input: the start and the end positions of the new move
	output: the game code that represents the result of the validation*/
	int updateBoard(const Coord& start, const Coord& end);

	/*validates a move
	input: the start and the end positions of the move
	output: the game code that represents the result of the validation*/
	int generalValidate(const Coord& start, const Coord& end) const;

	/*checks if no pieces blocking the way for moving the piece
	input: the start and the end positions
	output: if the path is clear from any pieces or not */
	bool isPathClear(const Coord& start, const Coord& end) const;

	/*checks if the move caused to the specified player's king be in check
	input: the start and the end positions of the move, if the check for the current player or for the opponent 
	output: if the move caused to a check or not */
	bool isInCheckAfterMove(const Coord& start, const Coord& end, bool isCurrentPlayer) const;

protected:
	Piece* _boardStatus[8][8];
	bool _isWhitePlayer;

private:
	Piece* wKing; 
	Piece* bKing;
};