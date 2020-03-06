#ifndef MINIMAP_H
#define MINIMAP_H

#include <SFML/Graphics.hpp>
#include "ObjectManager.h"

class miniMap: public sf::Sprite
{
public:
	miniMap(ObjectManager*);
	~miniMap();

	void draw(sf::RenderTarget& target) const;
private:
	ObjectManager* objMan_;
};

#endif // !MINIMAP_H

