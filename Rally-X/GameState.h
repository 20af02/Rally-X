#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "TileMap.h"
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

class GameState: public State
{
public:
	//Constructors/Deconstructors
	GameState(State_Data*);
	~GameState();
	
	void updateViews(const float& dt);
	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void updatePlayerGUI(const float& dt);
	void updateTileMap(const float& dt);
	void updateCollision(const float& dt);
	void updatePlayer(const float& dt);
	void updateEnemies(const float& dt);

	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
	
private:
	sf::View playerView;
	sf::View GUI_View;
	sf::Texture texture;
	sf::RenderTexture renderTexture;
	sf::Sprite renderSprite;
	TileMap* tilemap;

	const int level[2] ={}, 
		player[2] = {},
	enemy[2] = {};

	//Functions
	
	void initViews();
	void initTextures();
	void initPlayer();
	void initPlayerGUI();
	void initSystems();
	void initTileMap();
	

};

#endif // !GAMESTATE_H