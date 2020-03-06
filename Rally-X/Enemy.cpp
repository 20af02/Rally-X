#include "Enemy.h"

Enemy::Enemy(): Car()
{
}

Enemy::~Enemy()
{
}

void Enemy::update(int type)
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
		if (direction != 1)
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
			//Collision with Car
	case 4:
		break;
		//Stop car
	case 5:
		break;
		//Start car
	case 6:
		break;
	}
}
