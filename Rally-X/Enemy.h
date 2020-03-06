#ifndef ENEMY_H
#define ENEMY_H
#include "Car.h"


class Enemy: public Car
{
public:
	Enemy();
	~Enemy();

	void update(int type = 0);

private:
};

#endif // !ENEMY_H

