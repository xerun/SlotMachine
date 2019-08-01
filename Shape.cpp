#include "Shape.h"
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;

/**
 Shape constructor that initializes the name
 and description, and assigns a unique ID
 to each Shape.

 @param name The user-supplied name.
 @param desc The user-supplied description.
 */
Shape::Shape(std::string _name, std::string desc) : name{ _name }, description{ desc } {
	static int _id = 0;
	id = ++_id;
}

/**
 Accessor method for the ID number.

 @return ID The ID number of the Shape.
 */
int Shape::getId() const { return id; }

/**
 Accessor method for the name.

 @return name The name of the Shape.
 */
string Shape::getName() const { return name; }

/**
 Accessor method for the description.

 @return description The description of the Shape.
 */
string Shape::getDesc() const { return description; }

/**
 Mutator method for the name.

 @param _name The user-supplied name.
 */
void Shape::setName(string _name) { name = _name; }

/**
 Mutator method for the description.

 @param desc The user-supplied description.
 */
void Shape::setDesc(string desc) { description = desc; }

/**
 Method to print out the Shape information.
 */
string Shape::toString() const{
	std::stringstream ss;
	ss << "Shape Information\n" << "-----------------\n";
	ss << setw(15) << left << "id:" << getId() << endl;
	ss << setw(15) << "Shape name:" << getName() << endl;
	ss << setw(15) << "Description:" << getDesc() << endl;
	ss << setw(15) << "B. box width:" << boxWidth() << endl;
	ss << setw(15) << "B. box height:" << boxHeight() << endl;
	ss << setw(15) << "Scr area:" << screenArea() << endl;
	ss << setw(15) << "Geo area:" << fixed << setprecision(2) << geoArea() << endl;
	ss << setw(15) << "Scr perimeter:" << setprecision(0) << screenPerimeter() << endl;
	ss << setw(15) << "Geo perimeter:" << setprecision(2) << geoPerimeter() << endl;
	ss << setw(15) << left << "Static type:" << typeid(this).name() << endl;
	ss << setw(15) << "Dynamic type:" << typeid(*this).name() << endl;
	ss << setprecision(0) << endl << endl;
	return ss.str();
}

/**
 ostream operator overload to print the toString function
 */
ostream& operator<<(ostream& sout, const Shape& shape)
{
	sout << shape.toString();
	return sout;
}