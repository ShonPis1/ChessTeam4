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
	int updateBoard(const Coord& src, const Coord& dest);

protected:
	Piece* _boardStatus[BOARD_SIZE][BOARD_SIZE];
	bool _isWhitePlayer;

private:
	/*initializes the chess pieces on the board
	input: none 
	output: none */
	void initializePieces();

	/*validates a move
	input: the start and the end positions of the move
	output: the game code that represents the result of the validation*/
	int generalValidate(const Coord& src, const Coord& dest) const;

	/*checks if no pieces blocking the way for moving the piece
	input: the start and the end positions
	output: if the path is clear from any pieces or not */
	bool isPathClear(const Coord& src, const Coord& dest) const;

	/*checks if the move caused to the specified player's king be in check
	input: the start and the end positions of the move, if the check for the current player or for the opponent
	output: if the move caused to a check or not */
	bool isInCheckAfterMove(const Coord& src, const Coord& dest, bool isCurrentPlayer) const;

	/*checks if piece is a pawn 
	input: the current piece 
	output: if the piece is pawn or not */
	bool isPawn(const char sign) const;

	Piece* wKing; 
	Piece* bKing;
};