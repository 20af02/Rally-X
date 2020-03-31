#include "Car.h"

Car::Car()
{
	animationState = carAnimationState::Up;
	stateTick = 0;
	turnDirection = Direction::up;
	speed = 2.f;
}


Car::~Car()
{
}


Direction Car::getDir()
{
	int count = 0;
	float temp = (float)animationState;
	while (temp > 1.f)
	{
		temp /= 3.f;
		count++;
	}

	//Round up if almost done turning
	if (temp >= 2.f / 3.f)
		count++;

	return (Direction)count;
}


carAnimationState Car::getAnimationState()
{
	return animationState;
}


void Car::update(Direction move, ObjectType collide)
{
	//Handle collision behavior
	switch (collide)
	{
	case player:
		break;
	case enemy:
		break;
	case flag:
		break;
	case smoke:
		break;
	case rock:
		break;
	case none:
		break;
	default:
		break;
	}

	//Handle input update

	//no neadless updates
	if (turnDirection != move && move != Direction::none)
	{
		turnDirection = move;
		this->stateTick = 2;
	}


	//handle movement
	updateMovement(turnDirection);
}


void Car::update(Direction move, ObjectType collide)
{

}


void Car::updateMovement(Direction dir)
{

	//Determine polar direction
	bool cw = true;
	if (dir < Direction::down)
		cw = true;
	else if (dir > Direction::down)
		cw = false;
	else
	{
		if (animationState < carAnimationState::Down)
			cw = true;
		else if(animationState > carAnimationState::Down)
			cw = false;
	}

	//Straight line behavior
	if(static_cast<int>(turnDirection) * 3 == static_cast<int>(animationState))
	{
		switch (turnDirection)
		{
		case Direction::none:
			break;
		case Direction::up:
			this->move(0.f, -speed);
			break;
		case Direction::right:
			this->move(speed, 0.f);
			break;
		case Direction::down:
			this->move(0.f, speed);
			break;
		case Direction::left:
			this->move(-speed, 0.f);
			break;
		default:
			break;
		}
		return;
	}

	//Turning behavior

	if (static_cast<int>(animationState) % 3 != 0)
	{

	}



	if (this->stateTick == 0)
	{
		//Increment and Wrap around
		if (cw)
			++animationState;
		else
			--animationState;

		stateTick = 2;
		return;
	}

	stateTick--;
}


