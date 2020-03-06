#include "GameState.h"


//Creates a new Gamestate given State data
GameState::GameState(State_Data* state_data) : State(state_data)
{	
	//Textures
	initTextures();

	//Graphics
	initViews();
	initTileMap();
	initHUD();

	//Objects
	initObjManager();
	initCollisionHandler();
}


//Deletes dynamic Memory
GameState::~GameState()
{
	delete this->tilemap;
	delete this->objMan;
	delete this->colisionHandler;
	delete this->hud;
}


//Updates Views of screen
void GameState::updateViews()
{

	//this->rTextSprites.draw()


	/*
	this->playerView.setCenter(
		this->initPlayer.getPos().x,
		this->initPlayer.getPos().y
	);*/

	
}


//updates input given time differential 
void GameState::updateInput(const float& dt)
{
	if (this->getKeyPressTime())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			std::cout << "W\n";
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			std::cout << "S\n";
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			std::cout << "A\n";
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			std::cout << "D\n";
	}

}


//Updates the tilemap
void GameState::updateTileMap()
{
}


//Updates behavior 
void GameState::updateBehavior()
{
	this->objMan->updateObjects();
	//Get input

}


//Handles Game Collisions
void GameState::updateCollision()
{
	colisionHandler->handleCollisions();
}


//Initializes Player & HUD views
void GameState::initViews()
{

	//Player View
	this->playerView.setSize(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width *(2.f/9.f)),
			static_cast<float>(this->stateData->gfxSettings->resolution.height)
		)
	);

	this->playerView.setCenter(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width*(7.f/9.f))/2.f,
			static_cast<float>(this->stateData->gfxSettings->resolution.height)/2.f
		)
	);

	//HUD View
	this->HUD_View.setSize(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width*(7.f/9.f)),
			static_cast<float>(this->stateData->gfxSettings->resolution.height)
		)
	);


	this->HUD_View.setCenter(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width * (8.f / 9.f)),
			static_cast<float>(this->stateData->gfxSettings->resolution.height) / 2.f
		)
	);

	//Set rTexture Views
	this->rTextMap.setView(this->playerView);
	this->rTextHUD.setView(this->HUD_View);
}



void GameState::initTextures()
{
	/*if (!this->textures["SPRITE_SHEET"].loadFromFile("Resources/Images/Rally-X-SpriteSheet.png"))
		std::cout << "ERROR: UNABLE_TO_LOAD_PLAYER_TEXTURE\n";*/
}


//Initializes and loads tilemap
void GameState::initTileMap()
{
	std::string temp,
	temp2, lineLevel, lineRotation;
	std::fstream levelIn, rotIn;
	int pos, tmp, tmp2;
	pos = tmp = tmp2 = 0;

	levelIn.open("Resources/Tilemap/levelMap.csv");
	rotIn.open("Resources/Tilemap/LevelMapRotations.csv");

	while (std::getline(levelIn, lineLevel) && std::getline(rotIn, lineRotation))
	{
		std::stringstream s(lineLevel);
		std::stringstream s2(lineRotation);
		while (std::getline(s, temp, ',') && std::getline(s2, temp2, ','))
		{
			tmp = std::stoi(temp);
			tmp2 = stoi(temp2);
			if (tmp < 0)
				tmp = 0;
			rots[pos] = tmp2;
			level[pos++] = tmp;
		}
	}
	levelIn.close();
	rotIn.close();

	this->tilemap = new TileMap();
	if (!tilemap->load("Resources/Images/Rally-X-SpriteSheet.png",
		sf::Vector2u(24, 24), this->level, this->rots, 42, 64, 0, 0))
		std::cout << "ERROR: UNABLE_TO_LOAD_TILEMAP\n";
}


//Initialize HUD
void GameState::initHUD()
{
	this->hud = new HUD(this->objMan);
}


//Initializes object mangaer
void GameState::initObjManager()
{
	this->objMan = new ObjectManager();

	objMan->addObject(player);

	//Add all game objects;
}


//Initializes Collision Handler
void GameState::initCollisionHandler()
{
	this->colisionHandler = new CollisionHandler(this->objMan, level, 24);
}


//Update Game
void GameState::update(const float& dt)
{
	this->updateKeytime(dt);
	this->updateInput(dt);
	this->updateBehavior();
	this->updateViews();
}


//Render Everything
void GameState::render(sf::RenderTarget* target)
{
	if (target == nullptr)
		target = this->stateData->window;
	target->clear();
	this->rTextMap.clear();
	this->rTextHUD.clear();

	//Tilemap
	this->tilemap->draw(*this->stateData->window, sf::RenderStates::Default);


	//Set texture to player view
	//this->renderTexture.setView(this->playerView);


	//Update render textures
	this->rTextMap.display();
	this->rTextHUD.display();
	//target->draw(&rTextSprites);
	

	//rTextGUI->draw(target);
	//target->draw(this->rTextSprites);
}