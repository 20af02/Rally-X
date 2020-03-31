#ifndef PLAYER_H
#define PLAYER_H
#include "Car.h"


//Player class
class Player: public Car
{
public:
	Player();
	~Player();

	void update(int type = 0);
	double getFuel();
	int getScore();
	int getLives();

private:
	double fuelLevel;
	int score, lives, flagCount;
	bool specialActive;
};

#endif // !PLAYER_H