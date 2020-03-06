#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	spriteManager = new SpriteManager("Resources/Images/Rally-X-SpriteSheet.png");
}

ObjectManager::~ObjectManager()
{
	for(int i = 0; i < 5; i++)
		for (int j = objects[i].size() - 1; j > -1; j--)
		{
			delete objects[i].at(j);
			objects[i].pop_back();
		}

	delete this->spriteManager;
}

void ObjectManager::addObject(ObjectType type)
{
	switch (type)
	{
		case 0:
			objects[0].push_back(new Player());
			break;
		case 1:
			objects[1].push_back(new Enemy());
			break;
		case 2:
			objects[2].push_back(new Flag());
			break;
		case 3:
			objects[3].push_back(new Smoke());
			break;
		case 4:
			objects[4].push_back(new Rock());
			break;
	default:
		break;
	}
}

GameObject& ObjectManager::getObject(ObjectType type, int index)
{
	return *objects[type].at(index);
}

void ObjectManager::updateObjects()
{
	/*
	for(int i =0; i < 5; i++)
		for (int j = 0; j < objects[i].size(); j++)
		{
			objects[i].at(j)->update();
		}
		*/
}

