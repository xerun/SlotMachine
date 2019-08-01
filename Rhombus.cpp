#include "Rhombus.h"
#include <sstream>
#include <iomanip>
using namespace std;

/**
 Rhombus constructor that calls
 the Shape constructor if the user
 provides a name and/or description.

 @param d			The diagonal of the rhombus
 @param name		The user-supplied name
 @param desc		The user-supplied description
 */
Rhombus::Rhombus(int _d, std::string name, std::string desc) : Shape(name, desc)
{
	d = _d % 2 == 0 ? _d + 1 : _d; // if d is even then store d+1 else store d
}

/**
 Accessor method for the Rhombus's height dimension.

 @return The height dimension
 */
int Rhombus::getHeight() const
{
	return d;
}

/**
 Accessor method for the Rhombus's width dimension.

 @return The width dimension
 */
int Rhombus::getWidth() const
{
	return d;
}

/**
 Mutator method for the Rhombus's height dimension.

 @param height The user-supplied height
 */
void Rhombus::setHeight(int _height)
{
	_height % 2 == 0 ? d = _height + 1 : d = _height; // if d is even then store d+1 else store d
}

/**
 Mutator method for the Rhombus's width dimension.

 @param width The user-supplied width
 */
void Rhombus::setWidth(int _width)
{
	_width % 2 == 0 ? d = _width + 1 : d = _width; // if d is even then store d+1 else store d
}

/**
 ostream operator overload to print the toString function
 */
std::ostream& operator<<(std::ostream& sout, const Rhombus& rhm)
{
	sout << rhm.toString();
	return sout;
}

/**
 Method to compute the Rhombus object's
 geometric area.

 @return The geometric area with type double
 */
double Rhombus::geoArea() const
{
	return pow(d, 2.0) / 2;
}

/**
 Method to compute the Rhombus object's
 screen area.

 @return The screen area with type int
 */
int Rhombus::screenArea() const
{
	double n = d / 2;
	return (2 * n * (n + 1) + 1);
}

/**
 Method to compute the Rhombus object's
 geometric perimeter.

 @return The geometric perimeter with type double
 */
double Rhombus::geoPerimeter() const
{
	return 2 * sqrt(2.0)* d;
}

/**
 Method to compute the Rhombus object's
 screen perimeter.

 @return The screen perimeter with type int
 */
int Rhombus::screenPerimeter() const
{
	return 2 * (d - 1);
}

/**
 Method that returns the height of the rhombus's
 bounding box.

 @return The box height with type int
 */
int Rhombus::boxHeight() const
{
	return d;
}

/**
 Method that returns the width of the rhombus's
 bounding box.

 @return The box width with type int
 */
int Rhombus::boxWidth() const
{
	return d;
}

/**
 Method to draw the Rhombus object on a vector.

 @param fChar    Foreground character
 @param bChar    Background character
 */
vector<vector<char>> Rhombus::draw(char fChar, char bChar) const
{
	vector<vector<char>> grid;
	// position and position2 are used to keep track of the edges of the rhombus
	int position{ this->boxHeight()/2 };
	int position2{ this->boxHeight()/2 };
	for (int r = 0; r < this->boxHeight(); ++r)
	{
		grid.push_back(vector<char>());
		// For the top half of the rhombus
		if (r < this->boxHeight() / 2)
		{
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
		else
		{// For the bottom half of the rhombus
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
			position += 1;
			position2 -= 1;
		}
	}
	return grid;
}