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
			spriteManager->setTexture(*objects[0].back(), SpriteManager::SheetSection::Cars,
				dynamic_cast<Car*>(objects[0].back())->getAnimationState(), 0);
			break;
		case 1:
			objects[1].push_back(new Enemy());
			spriteManager->setTexture(*objects[1].back(), SpriteManager::SheetSection::Cars,
				dynamic_cast<Car*>(objects[1].back())->getAnimationState(), 1);
			break;
		case 2:
			objects[2].push_back(new Flag());
			spriteManager->setTexture(*objects[2].back(), SpriteManager::SheetSection::Flags,
				2, 0);
			break;
		case 3:
			objects[3].push_back(new Smoke());
			spriteManager->setTexture(*objects[3].back(), SpriteManager::SheetSection::Obstacles,
				3, 0);
			break;
		case 4:
			objects[4].push_back(new Rock());
			spriteManager->setTexture(*objects[4].back(), SpriteManager::SheetSection::Obstacles,
				1, 0);
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
	//Player
	for (unsigned int i = 0; i < objects[0].size(); i++)
	{
		//If Animated
		if(dynamic_cast<Car*>(objects[0].at(i))->getStateTick())
			spriteManager->setTexture(*objects[0].at(i), SpriteManager::SheetSection::Cars,
				dynamic_cast<Car*>(objects[0].at(i))->getAnimationState(), 0);
	}

	//Enemy
	for (unsigned int i = 0; i < objects[1].size(); i++)
	{
		//If Animated
		if (dynamic_cast<Car*>(objects[1].at(i))->getStateTick())
			spriteManager->setTexture(*objects[1].at(i), SpriteManager::SheetSection::Cars,
				dynamic_cast<Car*>(objects[1].at(i))->getAnimationState(), 1);
	}
}


void ObjectManager::drawObjects(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(unsigned int i = 0; i < 5; i++)
		for (unsigned int j = 0; j < objects[i].size(); j++)
		{
			target.draw(*dynamic_cast<sf::Sprite*>(objects[i].at(j)));
		}
}

