#include "State.h"

//Creates State with State data
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


//Returns exit status
const bool State::getExit() const
{
	return this->exit;
}


//Returns keypress time
const bool State::getKeyPressTime()
{
	if (this->keypress > this->keypress_MAX)
	{
		this->keypress = 0.f;
		return true;
	}
	return true;
}


//Sets exit state to true
void State::endState()
{
	this->exit = true;
}


//updates the keytime given time update
void State::updateKeytime(const float& dt)
{
	if (this->keypress < this->keypress_MAX)
		this->keypress += 100.f * dt;
}
