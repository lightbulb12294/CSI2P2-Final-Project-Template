#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <vector>
#include <utility>
#include <tuple>
#include "./shapes/Shape.h"

/**
 * @brief The class manages data of each level.
 * @details The class could load level with designated input file and record. The level itself will decide when to create next monster.
 * @see DataCenter::level
*/
class Level
{
public:
	Level() {}
	void init();
	void load_level(int lvl);
	void update();
	void draw();
	bool is_onroad(const Rectangle &region);
	Rectangle grid_to_region(const Point &grid) const;
	const std::vector<Point> &get_road_path() const
	{ return road_path; }
	int remain_monsters() const {
		int res = 0;
		for(auto &i : num_of_monsters) res += i;
		return res;
	}
private:
	/**
	 * @var road_path
	 * @brief Stores the monster's attack route, whose Point is represented in grid format.
	 **
	 * @var level
	 * @brief The index of current level.
	 **
	 * @var grid_w
	 * @brief Number of grid in x-direction.
	 **
	 * @var grid_h
	 * @brief Number of grid in y-direction.
	 **
	 * @var monster_spawn_counter
	 * @brief Time remaining for the next monster to spawn.
	 **
	 * @var num_of_monsters
	 * @brief Number of each different type of monsters.
	*/
	std::vector<Point> road_path;
	int level;
	int grid_w;
	int grid_h;
	int monster_spawn_counter;
	std::vector<int> num_of_monsters;
};

#endif
