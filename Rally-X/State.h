#ifndef STATE_H
#define STATE_H


#include "GraphicsSettings.h"
#include <SFML/Graphics.hpp>
#include <vector>


class State;

//Simple Struct for State data
struct State_Data
{
	sf::RenderWindow* window;
	GraphicsSettings* gfxSettings;
	std::vector<State*>* states;
};


//Default State
class State
{
public:
	//Constructors/Deconstructors
	State(State_Data* state_data);
	virtual ~State();

	//Accessors
	const bool getExit() const;
	const bool getKeyPressTime();


	//std::map<std::string, sf::Texture> textures;

	//Functions
	void endState();

		//Virtual
	virtual void updateKeytime(const float& dt);	
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
protected:
	//std::vector<State*>* states;
	State_Data* stateData;
	
	//sf::RenderWindow* window;
	bool exit;

	//Track keypress time
	float keypress, keypress_MAX;

private:

};


#endif // !STATE_H