#ifndef TOWER_H_INCLUDED
#define TOWER_H_INCLUDED

#include "../Object.h"
#include "../shapes/Circle.h"
#include "../shapes/Rectangle.h"
#include <allegro5/bitmap.h>
#include <string>
#include "Bullet.h"

enum class TowerType;
class Monster;

/**
 * @brief Tower base class.
 * @details The class inherits from Object. Circle here represents its position (x and y) and attack range (r).
*/
class Tower : public Object
{
public:
	Tower(const Point &p, double attack_range, int attack_freq, TowerType type);
	virtual ~Tower() {}
	void update();
	virtual bool attack(Object *target);
	void draw();
	Rectangle get_region() const;
	virtual Bullet *create_bullet(Object *target) = 0;
	virtual const double attack_range() const = 0;
	TowerType type;
private:
	/**
	 * @var attack_freq
	 * @brief Tower attack frequency. This variable will be set by its child classes.
	 **
	 * @var counter
	 * @brief Tower attack cooldown.
	*/
	int attack_freq;
	int counter;
	ALLEGRO_BITMAP *bitmap;
};

#endif
