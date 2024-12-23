#include "Board.h"

Board::Board() // check
{
	King whiteKing(4, 7, true);
	King blackKing(4, 0, false);
	Rook rook1(7, 0, true);
	Rook rook2(7, 7, true);
	Rook rook3(0, 0, false);
	Rook rook4(0, 7, false);

	_boardStatus[4][7] = whiteKing;
	_boardStatus[4][0] = blackKing;
	_boardStatus[7][0] = rook1;
	_boardStatus[7][7] = rook2;
	_boardStatus[0][0] = rook3;
	_boardStatus[0][7] = rook4;
}

Board::~Board() {}

void Board::updateBoard(const Coord start, const Coord end)
{
	generalValidate(start, end);
	NullPiece nullPiece(start);
	_boardStatus[end.getX()][end.getY()] = _boardStatus[start.getX()][start.getY()];
	_boardStatus[start.getX()][start.getY()] = nullPiece;
	_isWhitePlayer = !_isWhitePlayer;
}

bool Board::generalValidate(const Coord start, const Coord end)
{
	if (_boardStatus[start.getX()][start.getY()].iswhite() != _isWhitePlayer) { throw(2); }
	if (_boardStatus[end.getX()][end.getY()].iswhite() == _isWhitePlayer && _boardStatus[end.getX()][end.getY()].getType() != '#') { throw(3); }
	
	char kingChar = _isWhitePlayer;
	int kingX = 0;
	int kingY = 0;
	for (int x = 0; x < 8; x++) 
	{
		for (int y = 0; y < 8; y++)
		{
			if (_boardStatus[x][y].getType() == kingChar) {
				kingX = x;
				kingY = y;
			}
		}
	}

	bool rookOrQueen = false;
	bool KingVisited = false;
	for (int x = 0; x < 8; x++)
	{
		if (x == kingX)
		{
			if (rookOrQueen) { throw(4); }
			KingVisited = true;
		}
		if (_boardStatus[x][kingY].getType() != '#')
		{
			rookOrQueen = false;
			if (_boardStatus[x][kingY].getType() == (_isWhitePlayer ? 'r' : 'R')) { //enemy rook
				if (KingVisited) { throw(4); }
				rookOrQueen = true;
			}
			if (KingVisited) { //supposed to throw, otherwise not rook (or queen)
				break;
			}
		}

	}
	rookOrQueen = false;
	KingVisited = false;
	for (int y = 0; y < 8; y++)
	{
		if (y == kingY)
		{
			if (rookOrQueen) { throw(4); }
			KingVisited = true;
		}
		if (_boardStatus[kingX][y].getType() != '#')
		{
			rookOrQueen = false;
			if (_boardStatus[kingX][y].getType() == (_isWhitePlayer ? 'r' : 'R')) { //enemy rook
				if (KingVisited) { throw(4); }
				rookOrQueen = true;
			}
			if (KingVisited) { //supposed to throw, otherwise not rook (or queen)
				break;
			}
		}
	}
		
	if (!start.isValid() || !end.isValid()) { throw(5); }
	if (start.getX() == end.getX() && start.getY() == end.getY()) { throw(7); }
}