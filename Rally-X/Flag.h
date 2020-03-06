#ifndef FLAG_H
#define FLAG_H




#include "GameObject.h"


class Flag: public GameObject
{
public:
	Flag();
	~Flag();

	void update(int type = 0);

	bool isSpecial();

private:
	bool special;
};

#endif // !FLAG_H