#ifndef GAME_H
#define GAME_H

//#include <SFML\Graphics.hpp>
//#include <vector>

//#include "GraphicsSettings.h"
//#include "State.h"
#include "GameState.h"

//Main game class
class Game
{
public:
	//Constructors/Deconstructors
	Game();
	~Game();

	//Functions
	void endApplication();

	//Update
	void updateDt();
	void updateEvents();
	void update();

	//Rendering
	void render();

	//Core Runtime
	void run();
private:
	//Graphics containers
	GraphicsSettings gfxSettings;
	State_Data stateData;
	sf::RenderWindow* window;
	sf::Event sf_event;

	//Timing
	sf::Clock clock;
	float dt;

	//Container for states
	std::vector<State*> states;

	//Initialization Helper
	void initVar();
	void initGraphicsSettings();
	void initWindow();
	void initStateData();
	void initStates();
};

#endif // !GAME_H