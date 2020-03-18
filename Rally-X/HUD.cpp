#include "HUD.h"


HUD::HUD(ObjectManager* objMan, GraphicsSettings* graphicsSettings) : objMan_(objMan), graphicsSettings_(graphicsSettings)
{
	this->miniMap_ = new miniMap(objMan, graphicsSettings);
}


HUD::~HUD()
{
	delete this->miniMap_;
}


//Draws a Tilemap to a rendertarget
void HUD::draw(sf::RenderTarget& target) const
{
	miniMap_->draw(target);

	return;
}
