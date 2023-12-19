#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Shape.h"

class Rectangle : public Shape
{
	struct OverlapVisitor : public ShapeVisitor
	{
		OverlapVisitor(const Rectangle &self) : result(false), self(self) {}
		void visitPoint(const Point &p);
		void visitRectangle(const Rectangle &r);
		void visitCircle(const Circle &c);
		bool result;
		const Rectangle &self;
	};
public:
	void accept(ShapeVisitor &v) const {
		v.visitRectangle(*this);
	}
	bool overlap(const Shape &s) const {
		OverlapVisitor v(*this);
		s.accept(v);
		return v.result;
	}
	double center_x() const { return (x1 + x2) / 2; }
	double center_y() const { return (y1 + y2) / 2; }
public:
	Rectangle() {}
	Rectangle(double x1, double y1, double x2, double y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
	double x1, y1, x2, y2;
};

#endif
