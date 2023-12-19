#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include "Shape.h"
#include <cmath>

class Point : public Shape
{
	struct OverlapVisitor : public ShapeVisitor
	{
		OverlapVisitor(const Point &self) : result(false), self(self) {}
		void visitPoint(const Point &p);
		void visitRectangle(const Rectangle &r);
		void visitCircle(const Circle &c);
		bool result;
		const Point &self;
	};
public:
	void accept(ShapeVisitor &v) const {
		v.visitPoint(*this);
	}
	bool overlap(const Shape &s) const {
		OverlapVisitor v(*this);
		s.accept(v);
		return v.result;
	}
	double center_x() const { return x; }
	double center_y() const { return y; }
public:
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	static double dist2(const Point &p1, const Point &p2) {
		return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	}
	static double dist(const Point &p1, const Point &p2) {
		return std::sqrt(dist2(p1, p2));
	}
	double x, y;
};

#endif
