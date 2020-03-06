#ifndef SMOKE_H
#define SMOKE_H



#include "GameObject.h"
class Smoke: public GameObject
{
public:
	Smoke();
	~Smoke();
	void update(int type= 0);
	bool isDead();

private:
	int despawnTimer;
};

#endif // !SMOKE_H