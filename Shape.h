#pragma once
#ifndef SHAPE_H_
#define SHAPE_H_
#include <vector>
#include <ostream>
using namespace std;
using Grid = vector<vector<char>>;
class Shape
{
int id;
std::string name;
std::string description;

public:
	Shape(std::string name, std::string desc);
	virtual ~Shape() = default;
	
	// Accessor and Mutator methods for the Shape data members
	int getId() const;
	std::string getName() const;
	std::string getDesc() const;
	void setName(std::string _name);
	void setDesc(std::string desc);

	// Methods to print the Shape information
	virtual string toString() const;
	friend std::ostream& operator<< (std::ostream& sout, const Shape& shape);

	// Pure virtual functions
	virtual double geoArea() const = 0;
	virtual double geoPerimeter() const = 0;
	virtual int screenArea() const = 0;
	virtual int screenPerimeter() const = 0;
	virtual int boxHeight() const = 0;
	virtual int boxWidth() const = 0;
	virtual vector<vector<char>> draw(char fChar = '*', char bChar = ' ') const = 0;
};
#endif /* SHAPE_H_ */