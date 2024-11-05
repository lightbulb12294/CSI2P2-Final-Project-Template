#ifndef DATACENTER_H_INCLUDED
#define DATACENTER_H_INCLUDED

#include <map>
#include <vector>
#include <allegro5/keycodes.h>
#include <allegro5/mouse.h>
#include "../shapes/Point.h"

class Player;
class Level;
class Monster;
class Tower;
class Bullet;

/**
 * @brief Stores generic global data and relatively small data structures.
 * @details The globally used data such as FPS (frames per second), windows size, game region, and states of input devices (mouse and keyboard).
 * Player and Level are stored here mainly because the objects are small enough that do not require complex management.
 * Other specific data like game objects (towers, monsters ... etc) or ALLEGRO_BITMAP will be managed by other center objects.
*/
class DataCenter
{
public:
	static DataCenter *get_instance() {
		static DataCenter DC;
		return &DC;
	}
	~DataCenter();
public:
	/**
	 * @var game_field_length
	 * @brief The width and height of game area (not window size). That is, the region excludes menu region.
	 * @details The game area is sticked to the top-left of the display window.
	 **
	 * @var key_state
	 * @brief Stores the keyboard state whether a key is being pressed.
	 * @details The states will be updated once a key is pressed, asynchronously with frame update.
	 * @see Game::execute()
	 **
	 * @var prev_key_state
	 * @brief Stores the keyboard states of the previous frame.
	 * @details The states will be updated every frame.
	 * @see Game::game_update()
	 **
	 * @var mouse
	 * @brief Stores the mouse position relative to the game window.
	 * @details The state will be update once the mouse is moved.
	 * @see Game::execute()
	 **
	 * @var mouse_state
	 * @brief Stores the state of every mouse button.
	 * @details The state will be update once a mouse button is clicked.
	 * @see Game::execute()
	 **
	 * @var prev_mouse_state
	 * @brief Stores the state of every mouse button of the previous frame.
	 * @details The state will be update every frame.
	 * @see Game::game_update()
	*/
	double FPS;
	int window_width, window_height;
	int game_field_length;
	bool key_state[ALLEGRO_KEY_MAX], prev_key_state[ALLEGRO_KEY_MAX];
	Point mouse;
	bool mouse_state[ALLEGRO_MOUSE_MAX_EXTRA_AXES], prev_mouse_state[ALLEGRO_MOUSE_MAX_EXTRA_AXES];
public:
	/**
	 * @var player
	 * @brief Stores the basic information that a player should have.
	 * @details For a tower-defense game, coin and health point is enough to represent a player.
	 * @see Player
	 **
	 * @var level
	 * @brief Loads and stores the information of a level.
	 * @see Level
	 **
	 * @var monsters
	 * @brief Raw list of Monster.
	 * @see Monster
	 **
	 * @var towers
	 * @brief Raw list of Tower.
	 **
	 * @var towerBullets
	 * @brief Raw list of Bullet.
	*/
	Player *player;
	Level *level;
	std::vector<Monster*> monsters;
	std::vector<Tower*> towers;
	std::vector<Bullet*> towerBullets;
private:
	DataCenter();
};

#endif
