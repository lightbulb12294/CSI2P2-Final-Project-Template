#include "FontCenter.h"
#include <allegro5/allegro_ttf.h>

// fixed settings
const char caviar_dreams_font_path[] = "./assets/font/Caviar_Dreams_Bold.ttf";
const char courier_new_font_path[] = "./assets/font/courbd.ttf";

void
FontCenter::init() {
	for(auto fs : FontSize::list) {
		caviar_dreams[fs] = al_load_ttf_font(caviar_dreams_font_path, fs, 0);
		courier_new[fs] = al_load_ttf_font(courier_new_font_path, fs, 0);
	}
}

FontCenter::~FontCenter() {
	for(auto &[size, font] : caviar_dreams)
		al_destroy_font(font);
	for(auto &[size, font] : courier_new)
		al_destroy_font(font);
}
