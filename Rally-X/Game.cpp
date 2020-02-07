#include "Game.h"

Game::Game()
{
	this->initVar();
	this->initWindow();
	//this->initStateData();
	//this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.back();
		this->states.pop_back();
	}
}

void Game::endApplication()
{
	std::cout << "END_APPLICATION\n";
}

void Game::updateDt()
{
	//Time it takes to update & render one frame
	this->dt = this->clock.restart().asSeconds();
}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->sf_event))
	{
		if (this->sf_event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateEvents();
	//
	//if (!this->states.empty())
	//{
	//	this->states.back()->update(this->dt);
	//	if (this->states.back()->getExit())
	//	{
	//		this->states.back()->endState();
	//		delete this->states.back();
	//		this->states.pop_back();
	//	}
	//}
	////End Application
	//else
	//{
	//	this->endApplication();
	//	this->window->close();
	//}
}

void Game::render()
{
	this->window->clear();

	//Render objects
	/*if (!this->states.empty())
		this->states.back()->render();*/

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->updateEvents();
		//this->update();
		this->render();
	}
}

void Game::initVar()
{
	this->window = nullptr;

	this->dt = 0.f;
	//Gridsize, DO LATER
}

void Game::initGraphicsSettings()
{
	this->gfxSettings.loadFromFile("Config/graphics.ini");
}


void Game::initWindow()
{
	if (this->gfxSettings.fullscreen)
		this->window = new sf::RenderWindow(
			this->gfxSettings.resolution, this->gfxSettings.windowName,
			sf::Style::Fullscreen);
	else
		this->window = new sf::RenderWindow(
			this->gfxSettings.resolution, this->gfxSettings.windowName,
			sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(this->gfxSettings.FrameRateLimit);
	this->window->setVerticalSyncEnabled(this->gfxSettings.vSync);
}

void Game::initStateData()
{
	this->stateData.window = this->window;
	this->stateData.gfxSettings = &this->gfxSettings;
	this->stateData.states = &this->states;
}

void Game::initStates()
{
	//this->states.push_back(new State())
}
