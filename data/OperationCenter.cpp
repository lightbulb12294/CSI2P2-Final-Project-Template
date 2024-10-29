#include "OperationCenter.h"
#include "DataCenter.h"
#include "TowerCenter.h"
#include "../monsters/Monster.h"
#include "../Player.h"

void OperationCenter::update() {
	// Update monsters first.
	_update_monster();
	// If any bullet overlaps with any monster, we delete the bullet, reduce the HP of the monster, and delete the monster if necessary.
	_update_monster_bullet();
	// If any monster reaches the end, hurt the player and delete the monster.
	_update_monster_player();
}

void OperationCenter::_update_monster() {
	DataCenter *DC = DataCenter::get_instance();
	for(Monster *monster : DC->monsters)
		monster->update();
}

void OperationCenter::_update_monster_bullet() {
	DataCenter *DC = DataCenter::get_instance();
	TowerCenter *TC = TowerCenter::get_instance();
	for(int i=0; i<(int)(DC->monsters.size()); ++i) {
		for(int j=0; j<(int)(TC->bullets.size()); ++j) {
			// Check if the bullet overlaps with the monster.
			if(DC->monsters[i]->shape->overlap(*(TC->bullets[j]->shape))) {
				DC->monsters[i]->HP -= TC->bullets[j]->get_dmg();
				TC->bullets.erase(TC->bullets.begin()+j);
				--j;
			}
		}
	}
}

void OperationCenter::_update_monster_player() {
	DataCenter *DC = DataCenter::get_instance();
	for(int i=0; i<(int)(DC->monsters.size()); ++i) {
		// Check if the monster is killed.
		if(DC->monsters[i]->HP <= 0) {
			// Monster gets killed. Player receives money.
			DC->player->coin += DC->monsters[i]->get_money();
			DC->monsters.erase(DC->monsters.begin()+i);
			--i;
			// Since the current monsster is killed, we can directly proceed to next monster.
			break;
		}
		// Check if the monster reaches the end.
		if(DC->monsters[i]->get_path().empty()) {
			DC->monsters.erase(DC->monsters.begin()+i);
			DC->player->HP--;
			--i;
		}
	}
}

void OperationCenter::draw() {
	_draw_monster();
}

void OperationCenter::_draw_monster() {
	DataCenter *DC = DataCenter::get_instance();
	for(Monster *monster : DC->monsters)
		monster->draw();
}
