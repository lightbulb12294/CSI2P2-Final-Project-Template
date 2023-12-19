#ifndef TOWERCENTER_H_INCLUDED
#define TOWERCENTER_H_INCLUDED

#include "../towers/Tower.h"
#include "../towers/Bullet.h"
#include <vector>
#include <string>
#include "../shapes/Point.h"

// fixed settings
enum class TowerType {
	ARCANE, ARCHER, CANON, POISON, STORM, TOWERTYPE_MAX
};
const std::vector<std::string> tower_full_img_path = {
	"./assets/image/tower/Arcane.png",
	"./assets/image/tower/Archer.png",
	"./assets/image/tower/Canon.png",
	"./assets/image/tower/Poison.png",
	"./assets/image/tower/Storm.png"
};
const std::vector<std::string> tower_menu_img_path = {
	"./assets/image/tower/Arcane_Menu.png",
	"./assets/image/tower/Archer_Menu.png",
	"./assets/image/tower/Canon_Menu.png",
	"./assets/image/tower/Poison_Menu.png",
	"./assets/image/tower/Storm_Menu.png"
};
const std::vector<std::string> tower_bullet_img_path = {
	"./assets/image/tower/Arcane_Beam.png",
	"./assets/image/tower/Archer_Beam.png",
	"./assets/image/tower/Canon_Beam.png",
	"./assets/image/tower/Poison_Beam.png",
	"./assets/image/tower/Storm_Beam.png"
};
const int tower_price[] = {50, 100, 150, 200, 250};

/**
 * @brief Stores and manages towers and bullets.
 * @details TowerCenter adopts [sigleton pattern](https://skyyen999.gitbooks.io/-study-design-pattern-in-java/content/singleton.html) to manage tower and bullet data.
 * All operations related to Tower and Bullet should be handled and done in the member functions.
 * If a outsider class objects need to interact with monsters or bullets, one must determine whether the interaction should be handled in TowerCenter or other control units.
 * Technically the bullet data are not part of tower data. If Bullet needs a more diverse and complex management, one should write another BulletCenter to achieve this.
 * @see Tower
 * @see Bullet
*/
class TowerCenter
{
public:
	static TowerCenter *get_instance() {
		static TowerCenter TC;
		return &TC;
	}
	void update();
	void draw();
	ALLEGRO_BITMAP *get_bitmap(TowerType type);
	Tower *create_tower(TowerType type, const Point &p);
	/**
	 * @var towers
	 * @brief Raw list of Tower.
	 **
	 * @var bullets
	 * @brief Raw list of Bullet.
	*/
	std::vector<Tower*> towers;
	std::vector<Bullet*> bullets;
private:
	TowerCenter();
};

#endif
