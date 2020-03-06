#include "Car.h"

Car::Car()
{
	state = 0;
	active = 1;
	direction = 1;
	speed = 2.f;
	stateTick = 0;
	animationState = 0;
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
