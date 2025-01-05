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
	Coord* coords;
	while (msgFromGraphics != "quit"){
		coords = communicator.getNewMove(msgFromGraphics);
		int gameCode = communicator.updateBoard(coords[0], coords[1]);
		communicator.sendBoard();

		msgToGraphics[0] = '0' + gameCode;
		msgToGraphics[1] = '\0';

		p.sendMessageToGraphics(msgToGraphics);

		msgFromGraphics = p.getMessageFromGraphics();

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