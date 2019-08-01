#include "Triangle.h"
using namespace std;
/**
 Triangle constructor that calls the Shape constructor.

 @param name The user-supplied name
 @param desc The user-supplied description

 */
Triangle::Triangle(string _name, string _desc) : Shape(_name, _desc) { }


/**
 Accessor method for the height of the Triangle.

 @return h The height dimension
 */
int Triangle::getHeight() const { return h; }


/**
 Accessor method for the base of the Triangle.

 @return b The base dimension
 */
int Triangle::getWidth() const { return b; }


/**
 Mutator method for the height of the Triangle.

 @param height The user-supplied value
 */
void Triangle::setHeight(int _height) { h = _height; }


/**
 Mutator method for the base of the Triangle.

 @param base The user-supplied value
 */
void Triangle::setWidth(int _base) { b = _base; }


/**
 Method to compute the triangle's geometric area.

 @return The area with type double.
 */
double Triangle::geoArea() const { return (h * b) / 2.0; }


/**
 Method that returns the height of the triangle's
 bounding box.

 @return The box height with type int
 */
int Triangle::boxHeight() const { return h; }


/**
 Method that returns the width of the triangle's
 bounding box.

 @return The box width with type int
 */
int Triangle::boxWidth() const { return b; }