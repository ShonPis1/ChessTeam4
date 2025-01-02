#pragma once

#include "Board.h"
#include <iostream>

class Communicator : Board
{
public:
	void sendBoard();
	Coord* getNewMove();

private:
	std::string protocolMsges;
	
};