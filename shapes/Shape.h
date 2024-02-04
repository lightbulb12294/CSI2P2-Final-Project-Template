#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

class Point;
class Rectangle;
class Circle;

enum class ShapeType {
	POINT, RECTANGLE, CIRCLE
};

/**
 * @brief Base shape class.
 * @details The functions of its derived classes are all defined in Shape.cpp.
 * @see Shape.cpp
*/
class Shape
{
public:
	virtual bool overlap(const Shape &s) const = 0;
	virtual double center_x() const = 0;
	virtual double center_y() const = 0;
	virtual const ShapeType getType() const = 0;
	virtual ~Shape() {}
};

#endif
