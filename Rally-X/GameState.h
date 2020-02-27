#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "TileMap.h"
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


class GameState: public State
{
public:
	//Constructors/Deconstructors
	GameState(State_Data*);
	~GameState();
	
	void updateViews();
	void updateInput(const float& dt);
	void updatePlayerInput();
	void updatePlayerGUI();
	void updateTileMap();
	void updateCollision();
	void updatePlayer();
	void updateEnemies();

	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
	
private:
	sf::View playerView;
	sf::View GUI_View;
	sf::Texture texture;
	sf::RenderTexture rTextSprites, rTextGUI;
	sf::Sprite renderSprite;
	TileMap* tilemap;

	//Tilemap
	int level[2688];
	int rots[2688];

	//Player player();
	//std::vector<Enemy> enemy();

	//Functions
	
	void initViews();
	void initTextures();
	void initPlayer();
	void initPlayerGUI();
	void initSystems();
	void initTileMap();
	
};

#endif // !GAMESTATE_H