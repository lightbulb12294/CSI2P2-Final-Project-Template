#include "Player.h"

// fixed settings
const int init_HP = 3;
const int init_coin = 100;
const int coin_freq = 60;
const int coin_increase = 5;

Player::Player() : HP(init_HP), coin(init_coin) {
	this->coin_freq = ::coin_freq;
	this->coin_increase = ::coin_increase;
	coin_counter = ::coin_freq;
}

void
Player::update() {
	if(coin_counter) coin_counter--;
	else {
		coin += coin_increase;
		coin_counter = coin_freq;
	}
}
