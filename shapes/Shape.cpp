#include "Shape.h"
#include "Point.h"
#include "Rectangle.h"
#include "Circle.h"
#include <algorithm>

using namespace std;

/**
 * @file Shape.cpp
 * @brief All interaction functions and visitor function implementations are defined here.
*/

bool checkOverlap(const Point &p1, const Point &p2) {
	return (p1.x == p2.x) && (p1.y == p2.y);
}

bool checkOverlap(const Point &p, const Rectangle &r) {
	return (r.x1 <= p.x && p.x <= r.x2) && (r.y1 <= p.y && p.y <= r.y2);
}

bool checkOverlap(const Point &p, const Circle &c) {
	return (c.r * c.r) <= Point::dist2(p, Point(c.x, c.y));
}

bool checkOverlap(const Rectangle &r1, const Rectangle &r2) {
	return !(r1.x2 < r2.x1 || r2.x2 < r1.x1 || r1.y2 < r2.y1 || r2.y2 < r1.y1);
}

bool checkOverlap(const Rectangle &r, const Circle &c) {
	double x = max(r.x1, min(c.x, r.x2));
	double y = max(r.y1, min(c.y, r.y2));
	return (c.r * c.r) >= Point::dist2(Point(c.x, c.y), Point(x, y));
}

bool checkOverlap(const Circle &c1, const Circle &c2) {
	double d = c1.r + c2.r;
	return (d * d) >= Point::dist2(Point(c1.x, c1.y), Point(c2.x, c2.y));
}

void
Point::OverlapVisitor::visitPoint(const Point &p) {
	result = checkOverlap(self, p);
}

void
Point::OverlapVisitor::visitRectangle(const Rectangle &r) {
	result = checkOverlap(self, r);
}

void
Point::OverlapVisitor::visitCircle(const Circle &c) {
	result = checkOverlap(self, c);
}

void
Rectangle::OverlapVisitor::visitPoint(const Point &p) {
	result = checkOverlap(p, self);
}

void
Rectangle::OverlapVisitor::visitRectangle(const Rectangle &r) {
	result = checkOverlap(self, r);
}

void
Rectangle::OverlapVisitor::visitCircle(const Circle &c) {
	result = checkOverlap(self, c);
}

void
Circle::OverlapVisitor::visitPoint(const Point &p) {
	result = checkOverlap(p, self);
}

void
Circle::OverlapVisitor::visitRectangle(const Rectangle &r) {
	result = checkOverlap(r, self);
}

void
Circle::OverlapVisitor::visitCircle(const Circle &c) {
	result = checkOverlap(self, c);
}
