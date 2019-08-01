#include "AcuteTriangle.h"
#include <sstream>
#include <iomanip>
using namespace std;
/**
 AcuteTriangle constructor that calls
 the Triangle constructor if the user
 provides a name and/or description.

 @param b			The length of the base of the triangle
 @param name		The user-supplied name
 @param desc		The user-supplied description
 */
AcuteTriangle::AcuteTriangle(int _b, string name, string desc) : Triangle(name, desc)
{
	_b = _b % 2 == 0 ? _b + 1 : _b;
	int height = (_b + 1) / 2;
	this->setWidth(_b);
	this->setHeight(height);
}

/**
 ostream operator overload to print the toString function
 */
std::ostream& operator<<(std::ostream& sout, const AcuteTriangle& act)
{
	sout << act.toString();
	return sout;
}

/**
 Method to compute the AcuteTriangle object's
 screen area.

 @return The screen area with type int
 */
int AcuteTriangle::screenArea() const { return pow(this->getHeight(), 2); }

/**
 Method to compute the AcuteTriangle object's
 geometric perimeter.

 @return The geometric perimeter with type double
 */
double AcuteTriangle::geoPerimeter() const { return this->getWidth() + 2 * sqrt(0.25 * pow(this->getWidth(), 2) + pow(this->getHeight(), 2)); }

/**
 Method to compute the AcuteTriangle object's
 screen perimeter.

 @return The screen perimeter with type int
 */
int AcuteTriangle::screenPerimeter() const { return 4 * (this->getHeight() - 1); }

/**
 Method to draw the AcuteTriangle object on a vector.

 @param fChar    Foreground character
 @param bChar    Background character
 */
vector<vector<char>> AcuteTriangle::draw(char fChar, char bChar) const
{
	vector<vector<char>> grid;
	// position and position2 are used to keep track of the edges of the rhombus
	int position{ this->boxWidth() / 2 };
	int position2{ this->boxWidth() / 2 };
	for (int r = 0; r < this->boxHeight(); ++r)
	{
		grid.push_back(vector<char>());
		for (int c = 0; c < this->boxWidth(); ++c)
		{
			if (c >= position && c <= position2)
			{
				grid[r].push_back(fChar);
			}
			else
			{
				grid[r].push_back(bChar);
			}
		}
		position -= 1;
		position2 += 1;		
	}
	return grid;
}
