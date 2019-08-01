#pragma once
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "Shape.h"
class Triangle :
	public Shape
{
int h;
int b;
public:
	// Constructor and virtual destructor
	Triangle(std::string _name, std::string _desc);
	virtual ~Triangle() = default;

	// Accessor and mutator methods for the height and base
	int getHeight() const;
	int getWidth() const;
	void setHeight(int _height);
	void setWidth(int _width);

	// Overridden virtual methods, common to Isosceles triangles
	virtual double geoArea() const override;
	virtual int boxHeight() const override;
	virtual int boxWidth() const override;
};
#endif /* TRIANGLE_H_ */