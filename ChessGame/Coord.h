#pragma once

class Coord
{
public:
	Coord(int x, int y);
	~Coord();

	// setters
	void setX(int x);
	void setY(int y);

	// getters
	int getX() const;
	int getY() const;

	// additional funcs

	/*checks if the coordinate is within the limit of the board
	input: none
	output: if the coordinate is valid of not */
	bool isValid() const;

	/*checks if two coordinate are not the same
	input: another coordinate
	output: if the two coordinate are not the same or not*/
	bool operator!=(const Coord& other) const;

	bool operator==(const Coord& other) const;

private:
	// represents a position in the chess board 
	int _x;
	int _y;
};