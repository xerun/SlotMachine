#pragma once
#ifndef RHOMBUS_H_
#define RHOMBUS_H_
#include "Shape.h"
class Rhombus :
	public Shape
{
int d;
public:
	// Constructor with default initialization of the name and description
	Rhombus(int _d, std::string name = "Ace", std::string desc = "Ace of diamond");

	// Accessor and mutator methods for the height and width data members
	int getHeight() const;
	int getWidth() const;
	void setHeight(int _height);
	void setWidth(int _width);

	// Methods to print the Shape information
	friend std::ostream& operator<< (std::ostream& sout, const Rhombus& rhm);

	// Overridden virtual methods
	virtual double geoArea() const override;
	virtual int screenArea() const override;
	virtual double geoPerimeter() const override;
	virtual int screenPerimeter() const override;
	virtual int boxHeight() const override;
	virtual int boxWidth() const override;
	virtual vector<vector<char>> draw(char fChar = '*', char bChar = ' ') const override;
};
#endif /* RHOMBUS_H_ */