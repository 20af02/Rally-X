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

	//Background blue screen for radar minimap
	sf::RectangleShape background(sf::Vector2f(graphicsSettings_->resolution.width * 2.f / 9.f, graphicsSettings_->resolution.height));
	sf::RectangleShape item(sf::Vector2f(4, 4));
	background.setFillColor(sf::Color(33, 71, 151));
	background.setPosition(sf::Vector2f(graphicsSettings_->resolution.width * 7.f / 9.f, graphicsSettings_->resolution.height / 2));


	target.draw(background);


	//Find position of entities and draw their square if active

	item.setFillColor(sf::Color::Red);

	//if needed use a goto to leave this loop - Ethan
	for (int i = 0; i < 8; i++)
	{
		/*
		if (this->objMan_->getObject(enemy, i).isActive())
		{
		pos = this->objMan_->getObject(enemy, i).getPosition();
		//Apply scale factor

		//Draw square
		target.draw(item);
		}
		*/
	}

	item.setFillColor(sf::Color::Yellow);

	//Draw flags
	for (int i = 0; i < 10; i++)
	{
		/*
		if (this->objMan_->getObject(flag, i).isActive())
		{
		pos = this->objMan_->getObject(flag, i).getPosition();
		//Apply scale factor

		//Draw square
		target.draw(item);
		}
		*/
	}

	//Draw player
	item.setFillColor(sf::Color::Blue);
	pos = this->objMan_->getObject(player, 0).getPosition();
	//Apply scale factor

	//Draw square


	return;
}
