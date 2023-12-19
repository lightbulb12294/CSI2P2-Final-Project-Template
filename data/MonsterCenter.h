#ifndef MONSTERCENTER_H_INCLUDED
#define MONSTERCENTER_H_INCLUDED

#include "../monsters/Monster.h"
#include "../shapes/Shape.h"
#include <vector>
#include <utility>

// fixed settings
enum class MonsterType {
	WOLF, CAVEMAN, WOLFKNIGHT, DEMONNIJIA, MONSTERTYPE_MAX
};
const char monster_imgs_root_path[][40] = {
	"./assets/image/monster/Wolf",
	"./assets/image/monster/CaveMan",
	"./assets/image/monster/WolfKnight",
	"./assets/image/monster/DemonNinja"
};

/**
 * @brief Stores and manages monsters (enemies).
 * @details MonsterCenter adopts [sigleton pattern](https://skyyen999.gitbooks.io/-study-design-pattern-in-java/content/singleton.html) to manage monster data.
 * All operations related to Monster should be handled and done in the member functions.
 * If a outsider class objects need to interact with monsters, one must determine whether the interaction should be handled in MonsterCenter or other control units.
 * @see Monster
*/
class MonsterCenter
{
public:
	static MonsterCenter *get_instance() {
		static MonsterCenter MC;
		return &MC;
	}
	void update();
	void draw();
	Monster *create_monster(MonsterType type, const std::vector<Point> &path);
	/**
	 * @brief Raw list of Monster.
	*/
	std::vector<Monster*> monsters;
private:
	MonsterCenter() {}
};

#endif
