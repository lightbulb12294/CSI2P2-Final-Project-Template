#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "shapes/Shape.h"
#include <type_traits>

template <class T>
class Object
{
static_assert(std::is_base_of<Shape, T>::value, "T must derive from Shape class.");
public:
	Object(const T &shape) : shape(shape) {}
	virtual ~Object() {}
public:
	// pure function for drawing the object
	virtual void draw() = 0;
public:
	T shape;
};

#endif
