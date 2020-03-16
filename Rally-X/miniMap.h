#ifndef MINIMAP_H
#define MINIMAP_H

#include <SFML/Graphics.hpp>
#include "ObjectManager.h"
#include "GraphicsSettings.h"

class miniMap: public sf::Sprite
{
public:
	miniMap(ObjectManager*, GraphicsSettings*);
	~miniMap();

	void draw(sf::RenderTarget& target) const;
private:
	ObjectManager* objMan_;
	GraphicsSettings* graphicsSettings_;
};

#endif // !MINIMAP_H

