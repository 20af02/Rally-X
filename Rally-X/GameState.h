#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "TileMap.h"
#include "ObjectManager.h"
#include "CollisionHandler.h"
#include "HUD.h"
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
	

	//Update FUnctions
	void updateViews();
	void updateInput(const float& dt);
	void updateTileMap();
	void updateBehavior();
	void updateCollision();

	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
	
private:
	//Views
	sf::View playerView;
	sf::View HUD_View;

	//RenderTextures
	sf::RenderTexture rTextMap, rTextHUD;
	sf::Sprite renderSprite;

	//HUD
	HUD* hud;

	//Tilemap 
	TileMap* tilemap;
	int level[2688];
	int rots[2688];

	//Objects
	CollisionHandler* colisionHandler;
	ObjectManager* objMan;

	//Initialization
		//Textures
	void initTextures();

	//Graphics
	void initViews();
	void initTileMap();
	void initHUD();

	//Objects
	void initObjManager();
	void initCollisionHandler();
	
};

#endif // !GAMESTATE_H