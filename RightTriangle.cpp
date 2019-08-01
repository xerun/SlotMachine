#include "RightTriangle.h"
#include <sstream>
#include <iomanip>
using namespace std;
/**
 RightTriangle constructor that calls
 the Triangle constructor if the user
 provides a name and/or description.

 @param b			The length of the base of the triangle
 @param name		The user-supplied name
 @param desc		The user-supplied description
 */
RightTriangle::RightTriangle(int _b, string name, string desc) : Triangle(name, desc)
{
	this->setWidth(_b);
	this->setHeight(_b);
}

/**
 ostream operator overload to print the toString function
 */
std::ostream& operator<<(std::ostream& sout, const RightTriangle& rht)
{
	sout << rht.toString();
	return sout;
}

/**
 Method to compute the RightTriangle object's
 screen area.

 @return The screen area with type int
 */
int RightTriangle::screenArea() const { return this->getHeight()* (this->getHeight() + 1) / 2; }

/**
 Method to compute the RightTriangle object's
 geometric perimeter.

 @return The geometric perimeter with type double
 */
double RightTriangle::geoPerimeter() const { return (2 + sqrt(2.0)) * this->getHeight(); }

/**
 Method to compute the RightTriangle object's
 screen perimeter.

 @return The screen perimeter with type int
 */
int RightTriangle::screenPerimeter() const { return 3 * (this->getHeight() - 1); }

/**
 Method to draw the RightTriangle object on a vector.

 @param fChar    Foreground character
 @param bChar    Background character
 */
vector<vector<char>> RightTriangle::draw(char fChar, char bChar) const
{
	vector<vector<char>> grid;
	// position and position2 are used to keep track of the edges of the rhombus
	int position{ 0 };
	for (int r = 0; r < this->boxHeight(); ++r)
	{
		grid.push_back(vector<char>());
		for (int c = 0; c < this->boxWidth(); ++c)
		{
			if (c <= position)
			{
				grid[r].push_back(fChar);
			}
			else
			{
				grid[r].push_back(bChar);
			}
		}
		position += 1;
	}
	return grid;
}
