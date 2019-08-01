#include "Rectangle.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
/**
 Rectangle constructor that calls
 the Shape constructor if the user
 provides a name and/or description.

 @param width   The width of the rectangle
 @param height  The height of the rectangle
 @param name       The user-supplied name
 @param desc       The user-supplied description
 */
Rectangle::Rectangle(int _width, int _height, string name, string desc) : h{ _height }, w{ _width }, Shape(name, desc) { }

/**
 Accessor method for the Rectangle's height dimension.

 @return The height dimension
 */
int Rectangle::getHeight() const { return h; }


/**
 Accessor method for the Rectangle's width dimension.

 @return The width dimension
 */
int Rectangle::getWidth() const { return w; }

/**
 Mutator method for the Rectangle's height dimension.

 @param height The user-supplied height
 */
void Rectangle::setHeight(int _height) { h = _height; }

/**
 Mutator method for the Rectangle's width dimension.

 @param width The user-supplied width
 */
void Rectangle::setWidth(int _width) { w = _width; }

/**
 Method to compute the Rectangle object's
 geometric area.

 @return The geometric area with type double
 */
double Rectangle::geoArea() const { return h * w; }

/**
 Method to compute the Rectangle object's
 screen area.

 @return The screen area with type int
 */
int Rectangle::screenArea() const { return h * w; }

/**
 Method to compute the Rectangle object's
 geometric perimeter.

 @return The geometric perimeter with type double
 */
double Rectangle::geoPerimeter() const { return 2 * (h + w); }

/**
 Method to compute the Rectangle object's
 screen perimeter.

 @return The screen perimeter with type int
 */
int Rectangle::screenPerimeter() const { return 2 * (h + w) - 4; }

/**
 Method that returns the height of the rectangle's
 bounding box.

 @return The box height with type int
 */
int Rectangle::boxHeight() const { return h; }

/**
 Method that returns the width of the rectangle's
 bounding box.

 @return The box width with type int
 */
int Rectangle::boxWidth() const { return w; }

/**
 Method to draw the Rectangle object on a vector.

 @param fChar    Foreground character
 @param bChar    Background character
 */
vector<vector<char>> Rectangle::draw(char fChar, char bChar) const
{
	std::vector<vector<char>> grid;
	for (int r = 0; r < this->boxHeight(); ++r)
	{
		grid.push_back(vector<char>());
		for (int c = 0; c < this->boxWidth(); ++c)
		{
			grid[r].push_back(fChar);
		}
	}
	return grid;
}
