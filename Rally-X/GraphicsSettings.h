#ifndef GRAPHICSSETTINGS_H
#define GRAPHICSSETTINGS_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

class GraphicsSettings
{
public:
	//Constructors & Deconstructors
	GraphicsSettings();
	~GraphicsSettings();
	//Variables
	std::string windowName;
	sf::VideoMode resolution;
	bool fullscreen, vSync;
	int FrameRateLimit;
	std::vector<sf::VideoMode> videoModes;

	//Functions
	void loadFromFile(const std::string);
};

#endif // !GRAPHICSSETTINGS_H