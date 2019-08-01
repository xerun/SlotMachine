#pragma once
#ifndef SLOT_H_
#define SLOT_H_
#include <array>
#include "Rhombus.h"
#include "Rectangle.h"
#include "AcuteTriangle.h"
#include "RightTriangle.h"
class SlotMachine
{
std::array<std::unique_ptr<Shape>, 3> reel{}; // reels represented by three unique pointers
void make_shapes(); // have reel Rk point at a random shape
void make_shape(int k); // randomly assigning different shapes to the reel
void display(); // prints the three bounding boxes side by side in a row
int getNumber(); // prompts the user for a non-negative number (>= 0)
public:
	SlotMachine()								= default; // default ctor
	SlotMachine(const SlotMachine&)				= delete; // copy ctor
	SlotMachine(SlotMachine&&)					= delete; // move ctor
	SlotMachine& operator=(const SlotMachine&)	= delete; // copy assignment
	SlotMachine& operator=(SlotMachine&&)		= delete; // move assignment
	virtual ~SlotMachine()						= default; // default dtor
	void run();
};

#endif /* SLOT_H_ */