#include "GraphicsSettings.h"


GraphicsSettings::GraphicsSettings()
{
	this->windowName = "Rally-X";
	this->resolution = sf::VideoMode(228, 224);
	this->fullscreen = false;
	this->vSync = false;
	this->FrameRateLimit = 60;
}

GraphicsSettings::~GraphicsSettings()
{
}

void GraphicsSettings::loadFromFile(const std::string filePath)
{

	std::ifstream ifs(filePath);

	if (ifs.is_open())
	{
		std::getline(ifs, this->windowName);
		ifs >> this->resolution.width >> this->resolution.height;
		ifs >> this->fullscreen;
		ifs >> this->FrameRateLimit;
		ifs >> this->vSync;
	}

	ifs.close();
}
