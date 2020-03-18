#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Smoke.h"
#include "Rock.h"
#include "Flag.h"

class ObjectManager
{
public:
	//Constructor & Deconstructor
	ObjectManager();
	~ObjectManager();

	//Functions
	void addObject(ObjectType);
	GameObject& getObject(ObjectType, int);

	//defualt update
	void updateObjects();

	void drawObjects(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;


private:
	std::vector<GameObject*> objects[5];
	SpriteManager* spriteManager;
};


#endif // !OBJECTMANAGER_H
