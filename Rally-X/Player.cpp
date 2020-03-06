#include "Player.h"

Player::Player(): Car()
{
	fuelLevel = 100.0;
	lives = 3;
	score = 0;
}

Player::~Player()
{
}

void Player::update(int type)
{
	switch (type)
	{

	//Walls
		//Collision with wall up
	case 0:
		//Not head on
		if (direction != 0)
			direction = direction;
		//Handle side collision
		else
			direction = direction;
			//random turn
		break;
		//Collision with wall down
	case 1:
		//Not head on
		if (direction !=1)
			direction = direction;
		//Handle side collision
		else
			direction = direction;
		break;
		//Collision with wall left
	case 2:
		//Not head on
		if (direction != 2)
			direction = direction;
		//Handle side collision
		else
			direction = direction;
		break;
		//Collision with wall right
	case 3:
		//Not head on
		if (direction != 3)
			direction = direction;
		//Handle side collision
		else
			direction = direction;
		break;

	//Game Objects
		//Collision with Enemy
	case 4:
		//Collision with Rock
	case 5:
		state = 0;
		break;
		//Input up
	case 6:
		break;
		//Input Down
	case 7:
		break;
		//Input Left
	case 8:
		break;
		//Input Right
	case 9:
		break;

	//scoring
	case 1000:
		score += 100;
	case 900:
		score += 100;
	case 800:
		score += 100;
	case 700:
		score += 100;
	case 600:
		score += 100;
	case 500:
		score += 100;
	case 400:
		score += 100;
	case 300:
		score += 100;
	case 200:
		score += 100;
	case 100:
		score += 100;
		break;

	default:
		break;
	}
}

int Player::getFuel()
{
	return fuelLevel;
}

int Player::getScore()
{
	return score;
}

int Player::getLives()
{
	return lives;
}
