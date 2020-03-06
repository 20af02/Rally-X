#ifndef ROCK_H
#define ROCK_H


#include "GameObject.h"


class Rock: public GameObject
{
public:
	Rock();
	~Rock();
	void update(int type = 0);
private:

};

#endif // !ROCK_H
