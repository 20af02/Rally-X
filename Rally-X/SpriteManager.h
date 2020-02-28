#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>


class SpriteManager
{
public:
	SpriteManager(std::string);
	~SpriteManager();
	enum SheetSection { Cars, MapTiles, Obstacles, Flags, Life };
	void setTexture(sf::Sprite&, SheetSection, int, int);
private:
	sf::Texture spriteSheet;
	int startCoordinates[5][2] = { {0, 0}, {0, 112}, {0, 80}, {1, 65}, {195, 65} };
	int gridSizes[5][2]{ {16, 16}, {24, 24}, {24, 24}, {15, 11}, {10, 10} };
};

#endif // !SPRITEMANAGER_H