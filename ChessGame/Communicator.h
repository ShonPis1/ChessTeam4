#pragma once

#include "Board.h"

using std::string;

#define EMPTY_SPACE_CHAR '#'
#define BUFFER_SIZE 66

class Communicator : public Board
{
public:
	char* sendBoard();
	//returns a new[] array of 2 coordinates (src, dest); the caller must delete[] it
	Coord* getNewMove(const std::string& move);

private:
	char boardString[BUFFER_SIZE];
};