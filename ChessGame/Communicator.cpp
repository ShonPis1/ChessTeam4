#include "Communicator.h"

char* Communicator::sendBoard(){
	int index = 0;
	for (int x = 7; x >= 0; x--) {
		for (int y = 0; y < 8; y++) {
			if (_boardStatus[x][y] == nullptr) {
				boardString[index++] = '#';
			}else{
				boardString[index++] = _boardStatus[x][y]->getType();
			}	
		}
	}

	boardString[64] = _isWhitePlayer ? '0' : '1';
	boardString[65] = NULL;
	return boardString;
}

Coord* Communicator::getNewMove(const std::string& move){
	Coord* newMove = new Coord[2]; 

	newMove[0] = Coord(move[1] - '1', move[0] - 'a');
	newMove[1] = Coord(move[3] - '1', move[2] - 'a');

	return newMove;
}
