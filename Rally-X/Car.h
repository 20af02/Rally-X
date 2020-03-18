#ifndef CAR_H
#define CAR_H

#include "GameObject.h"
#include "SpriteManager.h"

class Car: public GameObject
{
public:
	Car();
	~Car();
	int getDir();
	int getAnimationState();
	virtual void update(int type = 0);
	int getStateTick();
protected:
	float speed;
	int direction, animationState, stateTick;
};

#endif // !CAR_H