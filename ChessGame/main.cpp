#include "Communicator.h"
#include "Pipe.h"
#include <thread>

using std::cout;
using std::endl;
using std::string;

int main(){
	srand(time_t(NULL));
	Pipe p;

	bool isConnect = p.connect();
	string ans;
	while (!isConnect)
	{
		cout << "Can't connect to graphics..." << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again..." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return 0;
		}
	}

	Communicator communicator;
	char* boardStatus = communicator.sendBoard(); 

	char msgToGraphics[1024];
	strcpy_s(msgToGraphics, boardStatus);
	p.sendMessageToGraphics(msgToGraphics);


	string msgFromGraphics = p.getMessageFromGraphics();
	while (msgFromGraphics != "quit"){
		cout << "Message from graphics: " << msgFromGraphics << endl;

		Coord* newMove = communicator.getNewMove(msgFromGraphics);

		communicator.updateBoard(newMove[0], newMove[1]);
		boardStatus = communicator.sendBoard();

		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		//communicator.updateBoard()
		//// YOUR CODE
		//strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation

		///******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0;
		///******* JUST FOR EREZ DEBUGGING ******/


		//// return result to graphics		
		//p.sendMessageToGraphics(msgToGraphics);

		//// get message from graphics
		//msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();



	/*int index = 0;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			std::cout << boardStatus[index++] << " ";
		}
		std::cout << std::endl;
	}*/

	return 0;
}