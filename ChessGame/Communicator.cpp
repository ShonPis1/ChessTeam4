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