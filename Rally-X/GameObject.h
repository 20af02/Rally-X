#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include "SpriteManager.h"

enum ObjectType{player, enemy, flag, smoke, rock};

class GameObject: public sf::Sprite
{
public:
	GameObject();
	virtual ~GameObject();

	virtual void update(int type= 0) = 0;
protected:
	int state;
	bool active;

private:
};

#endif // !GAMEOBJECT_H

