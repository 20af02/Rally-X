#ifndef PLAYER_H
#define PLAYER_H
#include "Car.h"


class Player: public Car
{
public:
	Player();
	~Player();

	void update(int type = 0);
	int getFuel();
	int getScore();
	int getLives();

private:
	double fuelLevel;
	int score, lives;
};

#endif // !PLAYER_H