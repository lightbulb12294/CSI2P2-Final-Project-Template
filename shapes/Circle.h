#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Shape.h"

/**
 * @see Shape.cpp
*/
class Circle : public Shape
{
public:
	bool overlap(const Shape &s) const;
	double center_x() const { return x; }
	double center_y() const { return y; }
	const ShapeType getType() const { return ShapeType::CIRCLE; }
public:
	Circle() {}
	Circle(double x, double y, double r) : x(x), y(y), r(r) {}
	double x, y, r;
};

#endif
