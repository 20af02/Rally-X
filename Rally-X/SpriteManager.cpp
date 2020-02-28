#include "SpriteManager.h"

SpriteManager::SpriteManager(std::string sheetFile)
{
	spriteSheet.loadFromFile(sheetFile);
}


SpriteManager::~SpriteManager()
{
}


void SpriteManager::setTexture(sf::Sprite& sprite, SheetSection section, int x, int y)
{
	int startX = startCoordinates[section][0] + gridSizes[section][0] * x;
	int startY = startCoordinates[section][1] + gridSizes[section][1] * y;

	sprite.setTexture(spriteSheet);
	//sprite.setTextureRect(sf::IntRect(startX, startY, endX, endY));
	sprite.setTextureRect(sf::IntRect(startX, startY, gridSizes[section][0], gridSizes[section][1]));
}
