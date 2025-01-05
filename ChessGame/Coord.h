#pragma once

#define BOARD_SIZE 8

class Coord 
{
public:
	Coord(int y, int x);
	Coord();
	~Coord();

	void setY(int y);
	void setX(int x);
	
	int getY() const;
	int getX() const;
	
	/*checks if the coordinate is within the limit of the board
	input: none
	output: if the coordinate is valid of not */
	bool isValid() const;

	/*checks if two coordinate are the same
	input: another coordinate
	output: if the two coordinate are the same or not*/
	bool operator==(const Coord& other) const;

private:
	// represents a position in the chess board 
	int _y;
	int _x;
};