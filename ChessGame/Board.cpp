#include "Board.h"

Board::Board() : _isWhitePlayer(true) {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			_boardStatus[y][x] = nullptr;
		}
	}

	initializePieces();
}

void Board::initializePieces(){
	_boardStatus[0][4] = new King(0, 4, true);
	wKing = _boardStatus[0][4];
	_boardStatus[7][4] = new King(7, 4, false);
	bKing = _boardStatus[7][4];

	_boardStatus[0][3] = new Queen(0, 3, true);
	_boardStatus[7][3] = new Queen(7, 3, false);

	_boardStatus[0][0] = new Rook(0, 0, true);
	_boardStatus[0][7] = new Rook(0, 7, true);
	_boardStatus[7][0] = new Rook(7, 0, false);
	_boardStatus[7][7] = new Rook(7, 7, false);

	_boardStatus[0][2] = new Bishop(0, 2, true);
	_boardStatus[0][5] = new Bishop(0, 5, true);
	_boardStatus[7][2] = new Bishop(7, 2, false);
	_boardStatus[7][5] = new Bishop(7, 5, false);

	_boardStatus[0][1] = new Knight(0, 1, true);
	_boardStatus[0][6] = new Knight(0, 6, true);
	_boardStatus[7][1] = new Knight(7, 1, false);
	_boardStatus[7][6] = new Knight(7, 6, false);


	for (int x = 0; x < BOARD_SIZE; x++) {
		_boardStatus[1][x] = new Pawn(1, x, true);
		_boardStatus[6][x] = new Pawn(6, x, false);
	}
}

Board::Board(const Board& other) : _isWhitePlayer(other._isWhitePlayer) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
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
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			delete _boardStatus[y][x];
		}
	}
}

int Board::updateBoard(const Coord& src, const Coord& dest) {
	int gameCode = generalValidate(src, dest);

	if (gameCode != 0 && gameCode != 1 && gameCode != 8) return gameCode;
		
	_isWhitePlayer = !_isWhitePlayer;
	_boardStatus[dest.getY()][dest.getX()] = _boardStatus[src.getY()][src.getX()];
	_boardStatus[src.getY()][src.getX()] = nullptr;

	_boardStatus[dest.getY()][dest.getX()]->setPosition(dest);
	return gameCode;
}

int Board::generalValidate(const Coord& src, const Coord& dest) const{
	//ensures start and end are within the board limits
	if (!src.isValid() || !dest.isValid()) return 5;

	//ensure the start and end positions aren't the same
	if (src == dest) return 7;

	//ensures there is a piece of the current player at the start position
	if (_boardStatus[src.getY()][src.getX()] == nullptr ||
		_boardStatus[src.getY()][src.getX()]->iswhite() != _isWhitePlayer) return 2;

	//ensures the destination doesn't contain a piece of the current player
	if (_boardStatus[dest.getY()][dest.getX()] != nullptr &&
		_boardStatus[dest.getY()][dest.getX()]->iswhite() == _isWhitePlayer) return 3;
	
	//ensures the move is legal: Pawn
	if (isPawn(_boardStatus[src.getY()][src.getX()]->getType())) {
		Pawn temp(src.getY(), src.getX(), _boardStatus[src.getY()][src.getX()]->iswhite());
		if (!temp.isMoveLegalPawn(dest, _boardStatus) || !isPathClear(src, dest)) return 6;
	}else {
		//ensures the move is legal 
		if (!_boardStatus[src.getY()][src.getX()]->isMoveLegal(dest) || !isPathClear(src, dest)) return 6;
	}

	//checks if the move make the current player's king be in check 
	if (isInCheckAfterMove(src, dest, true)) return 4;

	//checks if the move make the opponent's king be in check 
	if (isInCheckAfterMove(src, dest, false)) return 1;

	//code 8 for checkmate.....................................................................

	return 0;
}

bool Board::isInCheckAfterMove(const Coord& src, const Coord& dest, bool isCurrentPlayer) const {
	//copy of this board to enable changes in boardStatus 
	Board tempBoard(*this);

	//simulating the move for change the board status 
	tempBoard._boardStatus[dest.getY()][dest.getX()] = tempBoard._boardStatus[src.getY()][src.getX()];
	tempBoard._boardStatus[src.getY()][src.getX()] = nullptr;
	tempBoard._boardStatus[dest.getY()][dest.getX()]->setPosition(dest);

	Piece* king = (isCurrentPlayer == _isWhitePlayer) ? tempBoard.wKing : tempBoard.bKing;
	if (king->getPosition() == src) king->setPosition(dest);
	

	bool isCheck = false;
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (tempBoard._boardStatus[y][x] != nullptr &&
				tempBoard._boardStatus[y][x]->iswhite() != king->iswhite()) {
				//if the opponent can attack the king
				if (isPawn(tempBoard._boardStatus[y][x]->getType())){
					Pawn temp(y, x, tempBoard._boardStatus[y][x]->iswhite());
					if (temp.isMoveLegalPawn(king->getPosition(), tempBoard._boardStatus) &&
						tempBoard.isPathClear(temp.getPosition(), king->getPosition())){
						isCheck = true;
						break;
					}
				}else {
					//ensures the move is legal 
					if (tempBoard._boardStatus[y][x]->isMoveLegal(king->getPosition()) &&
						tempBoard.isPathClear(Coord(y, x), king->getPosition())){
						isCheck = true;
						break;
					}
				}
			}
		}
	}

	if (king->getPosition() == dest) king->setPosition(src);
	return isCheck;
}

bool Board::isPawn(const char sign) const { return (sign == 'P' || sign == 'p');  }

bool Board::isPathClear(const Coord& src, const Coord& dest) const {
	int dy = dest.getY() - src.getY();
	int dx = dest.getX() - src.getX();
	
	//straight line
	if (dy == 0) {
		int directionX = (dx > 0) ? 1 : -1;
		for (int x = src.getX() + directionX; x * directionX < dest.getX() * directionX; x += directionX) {
			if (_boardStatus[src.getY()][x] != nullptr) return false;
		}
	}

	if (dx == 0) {
		int directionY = (dy > 0) ? 1 : -1; 
		for (int y = src.getY() + directionY; y * directionY < dest.getY() * directionY; y += directionY) {
			if (_boardStatus[y][src.getX()] != nullptr) return false;
		}
	}


	//diagonal lines
	if (std::abs(dy) == std::abs(dx)) {
		int directionY = (dy > 0) ? 1 : -1;
		int directionX = (dx > 0) ? 1 : -1;

		for (int y = src.getY() + directionY, x = src.getX() + directionX; y * directionY < dest.getY() * directionY && 
			x * directionX < dest.getX() * directionX; y += directionY, x += directionX) {
				if (_boardStatus[y][x] != nullptr) return false;
		}	
	}
	return true;
}

