#include "miniMap.h"

miniMap::miniMap(ObjectManager* objMan, GraphicsSettings* graphicsSettings): objMan_(objMan), graphicsSettings_(graphicsSettings)
{
}

miniMap::~miniMap()
{
}

void miniMap::draw(sf::RenderTarget& target) const
{
	sf::Vector2f pos;

	sf::RectangleShape background(sf::Vector2f(graphicsSettings_->resolution.width * 2.f / 9.f, graphicsSettings_->resolution.height));
	background.setFillColor(sf::Color(33, 71, 151));
	background.setPosition(sf::Vector2f(graphicsSettings_->resolution.width * 7.f / 9.f, graphicsSettings_->resolution.height / 2));

	target.draw(background);
	//if needed use a goto to leave this loop - Ethan
	for (int i = 0; i < 8; i++)
	{
		pos = this->objMan_->getObject(enemy, i).getPosition();


	}


	return;
}
