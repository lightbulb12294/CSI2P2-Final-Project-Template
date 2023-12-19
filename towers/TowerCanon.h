#ifndef TOWERCANON_H_INCLUDED
#define TOWERCANON_H_INCLUDED

#include "../data/TowerCenter.h"
#include "../shapes/Point.h"

// fixed settings: TowerCanon attributes
class TowerCanon : public Tower
{
public:
	TowerCanon(const Point &p) : Tower(p, 200, 120, TowerType::CANON) {}
	Bullet *create_bullet(Object<Rectangle> *target) {
		const Point &p = Point(shape.center_x(), shape.center_y());
		const Point &t = Point(target->shape.center_x(), target->shape.center_y());
		return new Bullet(p, t, tower_bullet_img_path[static_cast<int>(type)], 300, 20, shape.r);
	}
};

#endif
