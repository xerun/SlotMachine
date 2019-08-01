#pragma once
#ifndef RIGHTTRIANGLE_H_
#define RIGHTTRIANGLE_H_
#include "Triangle.h"
class RightTriangle :
	public Triangle
{
public:
	// Constructor with default initialization of the name and description
	RightTriangle(int _b, std::string name = "Carpenter's sqaure", std::string desc = "One right and two acute angles");

	// Methods to print the Shape information
	friend std::ostream& operator<< (std::ostream& sout, const RightTriangle& rht);

	// Overridden virtual methods
	virtual int screenArea() const override;
	virtual double geoPerimeter() const override;
	virtual int screenPerimeter() const override;
	virtual vector<vector<char>> draw(char fChar = '*', char bChar = ' ') const override;
};
#endif /* RIGHTTRIANGLE_H_ */