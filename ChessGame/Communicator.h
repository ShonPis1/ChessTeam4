#pragma once

#include "Board.h"

using std::string;

#define EMPTY_SPACE_CHAR '#'
#define BUFFER_SIZE 66

class Communicator : public Board
{
public:
	char* sendBoard();
	Coord* getNewMove(const std::string& move);

private:
	char boardString[BUFFER_SIZE];
};