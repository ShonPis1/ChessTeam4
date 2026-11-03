#include "Communicator.h"
#include "Pipe.h"
#include <thread>

using std::cout;
using std::endl;
using std::string;

int main(){
	Pipe p;

	bool isConnect = p.connect();
	string ans;
	while (!isConnect){
		cout << "Can't connect to graphics..." << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0"){
			cout << "trying connect again..." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}else{
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
		delete[] coords;
		communicator.sendBoard();

		msgToGraphics[0] = '0' + gameCode;
		msgToGraphics[1] = '\0';

		p.sendMessageToGraphics(msgToGraphics);

		msgFromGraphics = p.getMessageFromGraphics();
		
		
		///******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0;
		///******* JUST FOR EREZ DEBUGGING ******/
	}

	p.close();
	return 0;
}