#include "Health.h"

Health::Health(const short healthPoints)
{
	this->healthPoints = healthPoints;
}

short Health::getHealthPoints() const
{
	return this->healthPoints;
}

void Health::reduceHealthPoints()
{
	this->healthPoints--;
}

bool Health::isAlive() const
{
	if (this->healthPoints > 0)
	{
		return true;
	}
	return false;
}

Health::~Health()
{
}
