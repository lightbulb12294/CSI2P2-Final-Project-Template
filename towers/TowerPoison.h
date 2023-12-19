#ifndef TOWERPOISON_H_INCLUDED
#define TOWERPOISON_H_INCLUDED

#include "../data/TowerCenter.h"
#include "../shapes/Point.h"

// fixed settings: TowerPoison attributes
class TowerPoison : public Tower
{
public:
	TowerPoison(const Point &p) : Tower(p, 150, 30, TowerType::POISON) {}
	Bullet *create_bullet(Object<Rectangle> *target) {
		const Point &p = Point(shape.center_x(), shape.center_y());
		const Point &t = Point(target->shape.center_x(), target->shape.center_y());
		return new Bullet(p, t, tower_bullet_img_path[static_cast<int>(type)], 480, 6, shape.r);
	}
};

#endif
