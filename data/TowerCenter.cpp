#include "TowerCenter.h"
#include "GAME_ASSERT.h"
#include "ImageCenter.h"
#include "../towers/TowerArcane.h"
#include "../towers/TowerArcher.h"
#include "../towers/TowerCanon.h"
#include "../towers/TowerPoison.h"
#include "../towers/TowerStorm.h"

TowerCenter::TowerCenter() {}

/**
 * @brief Call update function of every tower and bullet.
 * @details The function will also detects if a bullet flies too far (exceeds its fly distance limit).
 * The collision detection with monsters is implemented in MonsterCenter.
 * @see Tower::update()
 * @see Bullet::update()
 * @see MonsterCenter::update()
*/
void
TowerCenter::update() {
	for(auto &tower : towers)
		tower->update();
	for(auto &bullet : bullets)
		bullet->update();
	// detect bullet lifecycle ended
	for(int i=0; i<(int)(bullets.size()); ++i) {
		if(bullets[i]->get_fly_dist() <= 0) {
			bullets.erase(bullets.begin()+i);
			--i;
		}
	}
}

/**
 * @brief Call draw function of each tower and bullet.
 * @see Tower::draw()
 * @see Bullet::draw()
*/
void
TowerCenter::draw() {
	for(auto &tower : towers)
		tower->draw();
	for(auto &bullet : bullets)
		bullet->draw();
}

/**
 * @brief Get the ALLEGRO_BITMAP* instance of the full image of a specific TowerType.
*/
ALLEGRO_BITMAP*
TowerCenter::get_bitmap(TowerType type) {
	GAME_ASSERT(type != TowerType::TOWERTYPE_MAX, "tower type error.");
	ImageCenter *IC = ImageCenter::get_instance();
	return IC->get(tower_full_img_path[static_cast<int>(type)]);
}

/**
 * @brief Create a Tower* instance by the type.
 * @param type the type of a tower.
 * @param p center point of the tower.
 * @return The curresponding Tower* instance.
*/
Tower*
TowerCenter::create_tower(TowerType type, const Point &p) {
	switch(type) {
		case TowerType::ARCANE: {
			return new TowerArcane(p);
		} case TowerType::ARCHER: {
			return new TowerArcher(p);
		} case TowerType::CANON: {
			return new TowerCanon(p);
		} case TowerType::POISON: {
			return new TowerPoison(p);
		} case TowerType::STORM: {
			return new TowerStorm(p);
		} case TowerType::TOWERTYPE_MAX: {}
	}
	GAME_ASSERT(false, "tower type error.");
}
