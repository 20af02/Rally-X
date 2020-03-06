#include "HUD.h"


HUD::HUD(ObjectManager* objMan) : objMan_(objMan)
{
	this->miniMap_ = new miniMap(objMan);
}


HUD::~HUD()
{
	delete this->miniMap_;
}

//Draws a Tilemap to a rendertarget
void HUD::draw(sf::RenderTarget& target) const
{

}
