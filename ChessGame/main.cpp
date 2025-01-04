#include "Communicator.h"

int main()
{
	Board board = Board();
	Communicator communicator;
	char* boardStatus = communicator.sendBoard();

	for (int i = 0; i < 66; i++) {
		std::cout << boardStatus[i];
	}
	std::cout << std::endl;

	int index = 0;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			std::cout << boardStatus[index++] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << boardStatus[0] << std::endl;
	int code = board.updateBoard(Coord(0, 0), Coord(0, 1));
	std::cout << code << std::endl;

	boardStatus = communicator.sendBoard();
	std::cout << boardStatus[1] << std::endl;

	std::cout << std::endl;
	index = 0;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			std::cout << boardStatus[index++] << " ";
		}
		std::cout << std::endl;
	}



	return 0;
}