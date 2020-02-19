/************************************************
Authors:
Ammaar Firozi, Nathanael Hagemeyer,
Jack Schilling, Adin Aberbach.

Project Goal:
Recreate the classic arcade game Rally-X in C++
with SFML.

************************************************/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    Game game;

	try
	{
		game.run();
	}
	catch (const std::exception&e)
	{
		std::cout << e.what() << '\n';
	}

    return 0;
}

