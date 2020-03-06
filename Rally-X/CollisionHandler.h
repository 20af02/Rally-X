#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H


#include "ObjectManager.h"


class CollisionHandler
{
public:
	CollisionHandler(ObjectManager*, int* Map, int GridSize);
	~CollisionHandler();

	void handleCollisions();

private:
	ObjectManager* objMan_;
	int* map_;
	int gridSize_;
};


#endif // !COLLISIONHANDLER_H