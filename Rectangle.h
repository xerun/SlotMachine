#pragma once
#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "Shape.h"
class Rectangle :
	public Shape
{
int h;
int w;
public:
	// Constructor with default initialization of the name and description
	Rectangle(int _width, int _height, std::string name = "Four-sided", std::string desc = "Four right angles");

	// Accessor and mutator methods for the height and width data members
	int getHeight() const;
	int getWidth() const;
	void setHeight(int _height);
	void setWidth(int _width);

	// Overridden virtual methods
	virtual double geoArea() const override;
	virtual int screenArea() const override;
	virtual double geoPerimeter() const override;
	virtual int screenPerimeter() const override;
	virtual int boxHeight() const override;
	virtual int boxWidth() const override;
	virtual vector<vector<char>> draw(char fChar = '*', char bChar = ' ') const override;
};
#endif /* RECTANGLE_H_ */