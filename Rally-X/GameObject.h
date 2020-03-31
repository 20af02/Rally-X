#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"

enum ObjectType{player, enemy, flag, smoke, rock, none = -1};

class GameObject: public sf::Sprite
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void update(int type= 0) = 0;
protected:
	bool active;

private:
};

#endif // !GAMEOBJECT_H

