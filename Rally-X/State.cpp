#include "State.h"


State::State(State_Data* state_data)
{
	this->stateData = state_data;
	this->exit = false;
	this->keypress = 0.f;
	this->keypress_MAX =10.f;
}

State::~State()
{

}

const bool State::getExit() const
{
	return this->exit;
}

const bool State::getKeyPressTime()
{
	if (this->keypress > this->keypress_MAX)
	{
		this->keypress = 0.f;
		return true;
	}
	return false;
}

void State::endState()
{
	this->exit = true;
}

void State::updateKeytime(const float& dt)
{
	if (this->keypress < this->keypress_MAX)
		this->keypress += 100.f * dt;
}
