#include "Car.h"

Car::Car()
{
	state = 0;
	active = 1;
	speed = 2.f;
}


Car::~Car()
{
}


int Car::getDir()
{
	return direction;
}

int Car::getAnimationState()
{
	return stateTick;
}


void Car::update(int type)
{
}

int Car::getStateTick()
{
	return stateTick;
}
