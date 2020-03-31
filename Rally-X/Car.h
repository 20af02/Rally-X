#ifndef CAR_H
#define CAR_H

#include "GameObject.h"
#include "SpriteManager.h"


enum class Direction
{
	none = -1, up, right, down, left
};


Direction& operator++(Direction& dir)
{
	if (static_cast<int>(dir) + 1 > 3)
		dir = Direction::up;
	else
		dir = static_cast<Direction>(static_cast<int>(dir) + 1);
	return dir;
}


Direction& operator--(Direction& dir)
{
	if (static_cast<int>(dir) -1 < 0)
		dir = Direction::left;
	else
		dir = static_cast<Direction>(static_cast<int>(dir) - 1);
	return dir;
}


enum class carAnimationState
{
	Up, UpRt, UpRtRt, 
	Right, RightRt, RightRtRt, 
	Down,
	LeftLftLft, LeftLft, 
	Left, 
	UpLftLft, UpLft
};


carAnimationState& operator++(carAnimationState& state)
{
	if(static_cast<int>(state) +1 > 11)
		state = carAnimationState::Up;
	else
	state = static_cast<carAnimationState>(
		static_cast<int>(state) + 1);
	return state;
}


carAnimationState& operator--(carAnimationState& state)
{
	if (static_cast<int>(state) - 1 < 0)
		state = carAnimationState::UpLft;
	else
		state = static_cast<carAnimationState>(
		static_cast<int>(state) - 1);
	return state;
}



class Car: public GameObject
{
public:
	Car();
	~Car();
	Direction getDir();
	carAnimationState getAnimationState();
	//virtual void update(int type = 0);

	void update(Direction move = Direction::none, ObjectType collide = ObjectType::none);

	void updateMovement(Direction);

	//int getStateTick();
protected:
	float speed;
	carAnimationState animationState;
	int stateTick;
	Direction turnDirection;
};

#endif // !CAR_H