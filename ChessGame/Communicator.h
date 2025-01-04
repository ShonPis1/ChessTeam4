#pragma once

#include "Board.h"
using std::string;

class Communicator : Board
{
public:
	char* sendBoard();
	//Coord& getNewMove();

private:
	char boardString[66];
};