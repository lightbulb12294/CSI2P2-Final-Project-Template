#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

class ShapeVisitor;
class Point;
class Rectangle;
class Circle;

/**
 * @brief Base shape class.
 * @details The interactions of each different kind shape is addressed with [visitor pattern](https://bear-1111.medium.com/%E8%A8%AA%E5%95%8F%E8%80%85%E6%A8%A1%E5%BC%8F-visitor-pattern-850c9d07ba9b).
 *          Types of interactions currently include:
 *          * Overlap checking.
 * 
 *          The real interaction functions are all defined in Shape.cpp.
 * @see Shape.cpp
*/
struct Shape
{
	/**
	 * @fn void accept(ShapeVisitor &v) const
	 * @brief Accepts the visitor's visitor class.
	 **
	 * @fn bool overlap(const Shape &s) const
	 * @brief Function for calling the overlap checking function.
	 **
	 * @fn double center_x() const
	 * @brief Center point of the shape.
	 **
	 * @fn double center_y() const
	 * @brief Center point of the shape.
	*/
	virtual void accept(ShapeVisitor &v) const = 0;
	virtual bool overlap(const Shape &s) const = 0;
	virtual double center_x() const = 0;
	virtual double center_y() const = 0;
	virtual ~Shape() {}
};

/**
 * @brief Visitor class of Shape.
 * @see Shape
*/
struct ShapeVisitor
{
	virtual void visitPoint(const Point &p) = 0;
	virtual void visitRectangle(const Rectangle &r) = 0;
	virtual void visitCircle(const Circle &c) = 0;
};

#endif
