#pragma once
#ifndef ACUTETRIANGLE_H_
#define ACUTETRIANGLE_H_
#include "Triangle.h"
class AcuteTriangle :
	public Triangle
{
public:
	// Constructor with default initialization of the name and description
	AcuteTriangle(int _b, std::string name = "Acute triangle", std::string desc = "All acute angels");

	// Methods to print the Shape information
	friend std::ostream& operator<< (std::ostream& sout, const AcuteTriangle& act);

	// Overridden virtual methods
	virtual int screenArea() const override;
	virtual double geoPerimeter() const override;
	virtual int screenPerimeter() const override;
	virtual vector<vector<char>> draw(char fChar = '*', char bChar = ' ') const override;
};

#endif /* ACUTETRIANGLE_H_ */