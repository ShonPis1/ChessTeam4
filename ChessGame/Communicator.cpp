
#include "Communicator.h"

void Communicator::sendBoard()
{
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			std::cout << _boardStatus[x][y].getType() << ' ';
		}
		std::cout << std::endl
	}
}