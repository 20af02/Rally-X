#include "Smoke.h"

Smoke::Smoke(): GameObject()
{
	despawnTimer = 3;
}

Smoke::~Smoke()
{
}

void Smoke::update(int type)
{
}

bool Smoke::isDead()
{
	return (despawnTimer < 0);
}
