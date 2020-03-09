#include "Flag.h"

Flag::Flag(): GameObject()
{
	special = 0;
}

Flag::~Flag()
{
}

void Flag::update(int type)
{
	switch (type)
	{
		//Base
	case 0:
		break;
	case 1:
		//Deconstructor, play animation
	default:
		break;
	}
}


bool Flag::isSpecial()
{
	return special;
}
