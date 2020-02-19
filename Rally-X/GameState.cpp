#include "GameState.h"

GameState::GameState(State_Data* state_data) : State(state_data)
{	
	initViews();
	initTextures();
	initPlayer();
	initPlayerGUI();

}

GameState::~GameState()
{
	delete this->tilemap;
}

void GameState::updateViews(const float& dt)
{

	this->tilemap->draw(this->renderTexture, sf::RenderStates::Default);
	this->stateData->window;

	/*
	this->playerView.setCenter(
		this->initPlayer.getPos().x,
		this->initPlayer.getPos().y
	);*/

	
}

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

void GameState::updatePlayerInput(const float& dt)
{
}

void GameState::updatePlayerGUI(const float& dt)
{
}

void GameState::updateTileMap(const float& dt)
{
}

void GameState::updateCollision(const float& dt)
{
}

void GameState::updatePlayer(const float& dt)
{
}

void GameState::updateEnemies(const float& dt)
{
}



void GameState::initViews()
{
	this->playerView.setSize(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width),
			static_cast<float>(this->stateData->gfxSettings->resolution.height)
		)
	);

	this->playerView.setCenter(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width)/2.f,
			static_cast<float>(this->stateData->gfxSettings->resolution.height)/2.f
		)
	);

	//GUI To do

}

void GameState::initTextures()
{
	/*if (!this->textures["SPRITE_SHEET"].loadFromFile("Resources/Images/Rally-X-SpriteSheet.png"))
		std::cout << "ERROR: UNABLE_TO_LOAD_PLAYER_TEXTURE\n";*/
}

void GameState::initPlayer()
{
}

void GameState::initPlayerGUI()
{
}

void GameState::initSystems()
{
}

void GameState::initTileMap()
{
	this->tilemap = new TileMap();
	if (!tilemap->load("Resources/Images/Rally-X-SpriteSheet.png",
		sf::Vector2u(32, 32), this->level, sf::IntRect(0,0,5,5)))
		std::cout << "ERROR: UNABLE_TO_LOAD_TILEMAP\n";

}


void GameState::update(const float& dt)
{
	this->updateKeytime(dt);
	this->updateInput(dt);
	this->updateViews(dt);
}


void GameState::render(sf::RenderTarget* target)
{
	if (target == nullptr)
		target = this->stateData->window;
	target->clear();
	this->renderTexture.clear();

	//Set texture to player view
	//this->renderTexture.setView(this->playerView);
	this->renderTexture.display();
	target->draw(this->renderSprite);

}