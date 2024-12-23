#include "Board.h"

Board::Board() // check
{

}

Board::~Board() {}

void Board::updateBoard(Coord start, Coord end)
{
	generalValidate(start, end);
	nullPiece nullpiece(start);
	_boardStatus[end.getX()][end.getY()] = _boardStatus[start.getX()][start.getY()];
	_boardStatus[start.getX()][start.getY()] = nullpiece;
}

bool Board::generalValidate(Coord start, Coord end)
{
	if (_boardStatus[start.getX()][start.getY()].iswhite() != _isWhitePlayer) { throw(2); }
	if (_boardStatus[end.getX()][end.getY()].iswhite() == _isWhitePlayer && _boardStatus[end.getX()][end.getY()].getType() != '#') { throw(3); }
	
	char kingChar = _boardStatus[end.getX()][end.getY()].iswhite() ? 'K' : 'k';
	for (int x = 0; x < 8; x++) //work more, what id the moven piece wasnt rook
	{
		if (x == end.getX())
		{
			x++;
		}
		if (_boardStatus[x][end.getY()].getType() == kingChar) { throw(4); }
	}
	for (int y = 0; y < 8; y++)
	{
		if (y == end.getY())
		{
			y++;
		}
		if (_boardStatus[y][end.getX()].getType() == kingChar) { throw(4); }
	}

	if (!start.isValid() || !end.isValid()) { throw(5); }
	if (start.getX() == end.getX() && start.getY() == end.getY()) { throw(7); }
}