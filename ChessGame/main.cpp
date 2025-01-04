<<<<<<< HEAD
#include "Communicator.h"

int main()
{
	Communicator* communicator = new Communicator();
	communicator->sendBoard();

	while (true)
	{
		Coord* coords = communicator->getNewMove();
		try
		{
			communicator->generalValidate(coords[0], coords[1]);
		}
		catch (int errorNum)
		{
			std::cout << "Error: #" << errorNum;
		}

		communicator->updateBoard(coords[0], coords[1]);
		communicator->sendBoard();
	}

	return 0;
}
=======
>>>>>>> 7e2efd9155e3d738cd46cedfd0d84953adfc008e
