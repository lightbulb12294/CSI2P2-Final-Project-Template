#include "Bullet.h"
#include "../data/ImageCenter.h"
#include "../data/DataCenter.h"
#include <algorithm>
#include <allegro5/bitmap_draw.h>
#include "../shapes/Circle.h"
#include "../shapes/Point.h"

Bullet::Bullet(const Point &p, const Point &target, const std::string &path, double v, int dmg, double fly_dist) : Object<Circle>({p.x, p.y, 0}) {
	ImageCenter *IC = ImageCenter::get_instance();
	this->fly_dist = fly_dist;
	this->dmg = dmg;
	bitmap = IC->get(path);
	shape.r = std::min(al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap)) * 0.8;
	double d = Point::dist(p, target);
	vx = (target.x - p.x) * v / d;
	vy = (target.y - p.y) * v / d;
}

/**
 * @brief Update the bullet position by its velocity.
*/
void
Bullet::update() {
	if(fly_dist == 0) return;
	DataCenter *DC = DataCenter::get_instance();
	double dx = vx / DC->FPS;
	double dy = vy / DC->FPS;
	double movement = Point::dist(Point(dx, dy), Point(0, 0));
	if(fly_dist > movement) {
		shape.x += dx;
		shape.y += dy;
		fly_dist -= movement;
	} else {
		shape.x += dx * fly_dist / movement;
		shape.y += dy * fly_dist / movement;
		fly_dist = 0;
	}
}

/**
 * @brief Draw the bullet.
*/
void
Bullet::draw() {
	al_draw_bitmap(bitmap, shape.x - al_get_bitmap_width(bitmap)/2, shape.y - al_get_bitmap_height(bitmap)/2, 0);
}
