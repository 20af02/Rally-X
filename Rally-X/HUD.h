#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "ObjectManager.h"
#include "miniMap.h"

class HUD
{
public:
	HUD(ObjectManager*);
	~HUD();
	void draw(sf::RenderTarget& target) const;
private:
	ObjectManager* objMan_;
	miniMap* miniMap_;
};

#endif // !HUD_H