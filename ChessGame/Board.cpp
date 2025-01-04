#include "Board.h"

Board::Board() : _isWhitePlayer(true) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			_boardStatus[i][j] = nullptr;
		}
	}

	_boardStatus[0][4] = new King(0, 4, true);
	 wKing = _boardStatus[0][4];
	_boardStatus[7][4] = new King(7, 4, false);
	 bKing = _boardStatus[7][4];

	_boardStatus[0][0] = new Rook(0, 0, true);  
	_boardStatus[0][7] = new Rook(0, 7, true); 
	_boardStatus[7][0] = new Rook(7, 0, false); 
	_boardStatus[7][7] = new Rook(7, 7, false); 

}

Board::Board(const Board& other) : _isWhitePlayer(other._isWhitePlayer) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (other._boardStatus[i][j] != nullptr) {
				_boardStatus[i][j] = other._boardStatus[i][j]->getCopy();
			}else {
				_boardStatus[i][j] = nullptr;
			}
		}
	}
	wKing = other.wKing;
	bKing = other.bKing;
}

Board::~Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete _boardStatus[i][j];
		}
	}
}

int Board::updateBoard(const Coord& start, const Coord& end) {
	int gameCode = generalValidate(start, end);
	_isWhitePlayer = !_isWhitePlayer;

	if (gameCode != 0 && gameCode != 1 && gameCode != 8) return gameCode;

	_boardStatus[end.getX()][end.getY()] = _boardStatus[start.getX()][start.getY()];
	_boardStatus[start.getX()][start.getY()] = nullptr;

	_boardStatus[end.getX()][end.getY()]->setPosition(end);
	return gameCode;
}

int Board::generalValidate(const Coord& start, const Coord& end) const{
	//ensures start and end are within the board limits
	if (!start.isValid() || !end.isValid()) return 5;

	//ensure the start and end positions aren't the same
	if (start == end) return 7;

	//ensures there is a piece of the current player at the start position
	if (_boardStatus[start.getX()][start.getY()] == nullptr ||
		_boardStatus[start.getX()][start.getY()]->iswhite() != _isWhitePlayer) {
		return 2;
	}

	//ensures the destination doesn't contain a piece of the current player
	if (_boardStatus[end.getX()][end.getY()] != nullptr &&
		_boardStatus[end.getX()][end.getY()]->iswhite() == _isWhitePlayer) return 3;

	//ensures the move is legal 
	if (!_boardStatus[start.getX()][start.getY()]->isMoveLegal(end) ||
		!isPathClear(start, end)) return 6;

	//checks if the move make the current player's king be in check 
	if (isInCheckAfterMove(start, end, true)) return 4;

	//checks if the move make the opponent's king be in check 
	if (isInCheckAfterMove(start, end, false)) return 1;

	//code 8 for checkmate.....................................................................

	return 0;
}

bool Board::isInCheckAfterMove(const Coord& start, const Coord& end, bool isCurrentPlayer) const {
	//copy of this board to enable changes in boardStatus 
	Board tempBoard(*this);

	//simulating the move for change the board status 
	tempBoard._boardStatus[end.getX()][end.getY()] = tempBoard._boardStatus[start.getX()][start.getY()];
	tempBoard._boardStatus[start.getX()][start.getY()] = nullptr;


	Piece* king = (isCurrentPlayer == _isWhitePlayer) ? tempBoard.wKing : tempBoard.bKing;

	//checking for an available attack on the king
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (tempBoard._boardStatus[i][j] != nullptr &&
				tempBoard._boardStatus[i][j]->iswhite() != king->iswhite()) {

				//if the opponent can attack the king 
				if (tempBoard._boardStatus[i][j]->isMoveLegal(king->getPosition()) &&
					tempBoard.isPathClear(Coord(i, j), king->getPosition())) {
					return true; 
				}
			}
		}
	}
	return false;
}

bool Board::isPathClear(const Coord& start, const Coord& end) const {
	//delta x and y 
	int dx = end.getX() - start.getX(); 
	int dy = end.getY() - start.getY();

	//straight line
	if (dx == 0) {
		int directionY = (dy > 0) ? 1 : -1; //-1 if the direction is negative and 1 if positive 

		for (int y = start.getY() + directionY; y < end.getY(); y++) { 
			if (_boardStatus[start.getX()][y] != nullptr) return false; 
		}
	}

	if (dy == 0) {
		int directionX = (dx > 0) ? 1 : -1;

		for (int x = start.getX() + directionX; x < end.getX(); x++) {
			if (_boardStatus[x][start.getY()] != nullptr) return false;
		}
	}

	//diagonal lines
	if (std::abs(dx) == std::abs(dy)) {
		int directionX = (dx > 0) ? 1 : -1;
		int directionY = (dy > 0) ? 1 : -1;

		for (int x = start.getX() + directionX, y = start.getY() + directionY; x > end.getX() && y > end.getY();
			x += directionX, y += directionY) {
			if (_boardStatus[x][y] != nullptr) return false;  
		}
	}

	return true;
}