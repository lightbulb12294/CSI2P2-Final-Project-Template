#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Shape.h"

class Circle : public Shape
{
	struct OverlapVisitor : public ShapeVisitor
	{
		OverlapVisitor(const Circle &self) : result(false), self(self) {}
		void visitPoint(const Point &p);
		void visitRectangle(const Rectangle &r);
		void visitCircle(const Circle &c);
		bool result;
		const Circle &self;
	};
public:
	void accept(ShapeVisitor &v) const {
		v.visitCircle(*this);
	}
	bool overlap(const Shape &s) const {
		OverlapVisitor v(*this);
		s.accept(v);
		return v.result;
	}
	double center_x() const { return x; }
	double center_y() const { return y; }
public:
	Circle() {}
	Circle(double x, double y, double r) : x(x), y(y), r(r) {}
	double x, y, r;
};

#endif
