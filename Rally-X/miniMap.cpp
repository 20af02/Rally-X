#include "miniMap.h"

miniMap::miniMap(ObjectManager* objMan, GraphicsSettings* graphicsSettings): objMan_(objMan), graphicsSettings_(graphicsSettings)
{
}

miniMap::~miniMap()
{
}


//Requires all 8 enemy cars, all 10 flags, and player to be initialized.
//Assumes map size is 64 tiles of 24 pixels each and sprites are drawn from the top left corner.
void miniMap::draw(sf::RenderTarget& target) const
{
	sf::Vector2f pos;
	//These values are used a lot. Storing them costs 2 floats of memory 
	//but significantly reduces our pointer calls
	float screenWidth = graphicsSettings_->resolution.width;
	float screenHeight = graphicsSettings_->resolution.height;

	//Background blue screen for radar minimap
	sf::RectangleShape background(sf::Vector2f(screenWidth * 2.f / 9.f, screenHeight / 2));
	sf::RectangleShape item(sf::Vector2f(4, 4));
	background.setFillColor(sf::Color(33, 71, 151));
	background.setPosition(sf::Vector2f(screenWidth * 7.f / 9.f, screenHeight * 0.3));


	target.draw(background);


	//Find position of entities and draw their square if active

	item.setFillColor(sf::Color::Red);

	//if needed use a goto to leave this loop - Ethan
	for (int i = 0; i < 8; i++)
	{
		/*
		if (this->objMan_->getObject(enemy, i).getState() == 0)
		{
		pos = this->objMan_->getObject(enemy, i).getPosition();
		//Apply scale factor
		//Map is 64 * 24 pixels by 42 * 24 pixels (before zooming). Take this and use as a ratio
		pos.x = (screenWidth * 2/9) * (pos.x / (64 * 24));
		pos.y = (screenHeight * 0.5) * (pos.y / (64 * 24));
		pos.x += screenWidth * 7/9; //Offset to account for HUD position
		pos.y += screenHeight * 0.3; //Offset to account for HUD position

		//Draw square
		item.setPosition(pos);
		target.draw(item);
		}
		*/
	}

	item.setFillColor(sf::Color::Yellow);

	//Draw flags
	for (int i = 0; i < 10; i++)
	{
		/*
		if (this->objMan_->getObject(enemy, i).getState() == 0)
		{
		pos = this->objMan_->getObject(enemy, i).getPosition();
		//Apply scale factor
		//Map is 64 * 24 pixels by 42 * 24 pixels (before zooming). Take this and use as a ratio
		pos.x = (screenWidth * 2/9) * (pos.x / (64 * 24));
		pos.y = (screenHeight * 0.5) * (pos.y / (64 * 24));
		pos.x += screenWidth * 7/9; //Offset to account for HUD position
		pos.y += screenHeight * 0.3; //Offset to account for HUD position

		//Draw square
		item.setPosition(pos));
		target.draw(item);
		}
		*/
	}

	//Draw player
	item.setFillColor(sf::Color::Blue);
	pos = this->objMan_->getObject(player, 0).getPosition();
	//Apply scale factor
	//Map is 64 * 24 pixels by 42 * 24 pixels (before zooming). Take this and use as a ratio
	pos.x = (screenWidth * 2 / 9) * (pos.x / (64 * 24));
	pos.y = (screenHeight * 0.5) * (pos.y / (64 * 24));
	pos.x += screenWidth * 7 / 9; //Offset to account for HUD position
	pos.y += screenHeight * 0.3; //Offset to account for HUD position

	//Draw square
	item.setPosition(pos);
	target.draw(item);

	return;
}
