#ifndef FONTCENTER_H_INCLUDED
#define FONTCENTER_H_INCLUDED

#include <vector>
#include <map>
#include <allegro5/allegro_font.h>

// fixed settings
namespace FontSize
{
	static const int SMALL = 12, MEDIUM = 24, LARGE = 36;
	static const std::vector<int> list({
		FontSize::SMALL, FontSize::MEDIUM, FontSize::LARGE
	});
};

/**
 * @brief Stores and manages fonts.
 * @details FontCenter adopts [sigleton pattern](https://skyyen999.gitbooks.io/-study-design-pattern-in-java/content/singleton.html) to manage font data.
 * While FontCenter is initializing, it will use the fixed settings to create ALLEGRO_FONT* instances and store them. The created font instances will be stored in map and use font size as the key.
*/
class FontCenter
{
public:
	static FontCenter *get_instance() {
		static FontCenter FC;
		return &FC;
	}
	~FontCenter();
	void init();
public:
	std::map<int, ALLEGRO_FONT*> caviar_dreams;
	std::map<int, ALLEGRO_FONT*> courier_new;
private:
	FontCenter() {}
};

#endif
