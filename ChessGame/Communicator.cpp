#include "Communicator.h"

char* Communicator::sendBoard(){
	int index = 0;
	for (int y = 7; y >= 0; y--) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if (_boardStatus[y][x] == nullptr) {
				boardString[index++] = EMPTY_SPACE_CHAR;
			}else{
				boardString[index++] = _boardStatus[y][x]->getType();
			}	
		}
	}

	boardString[64] = _isWhitePlayer ? '0' : '1';
	boardString[65] = NULL;
	std::cout << boardString << std::endl;
	return boardString;
}

Coord* Communicator::getNewMove(const std::string& move){
	Coord* newMove = new Coord[2]; 

	//a move looks like "e2e4"; anything else becomes an out-of-bounds coordinate,
	//which Board::updateBoard rejects with code 5
	if (move.size() < 4) {
		newMove[0] = Coord(-1, -1);
		newMove[1] = Coord(-1, -1);
		return newMove;
	}

	newMove[0] = Coord(move[1] - '1', move[0] - 'a');
	newMove[1] = Coord(move[3] - '1', move[2] - 'a');

	return newMove;
}
