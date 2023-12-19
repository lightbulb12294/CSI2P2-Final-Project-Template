#ifndef TOWERARCANE_H_INCLUDED
#define TOWERARCANE_H_INCLUDED

#include "../data/TowerCenter.h"
#include "../shapes/Point.h"

// fixed settings: TowerArcane attributes
class TowerArcane : public Tower
{
public:
	TowerArcane(const Point &p) : Tower(p, 160, 60, TowerType::ARCANE) {}
	Bullet *create_bullet(Object<Rectangle> *target) {
		const Point &p = Point(shape.center_x(), shape.center_y());
		const Point &t = Point(target->shape.center_x(), target->shape.center_y());
		return new Bullet(p, t, tower_bullet_img_path[static_cast<int>(type)], 480, 4, shape.r);
	}
};

#endif
