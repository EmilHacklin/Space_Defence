#pragma once
class Health
{
private:
	short healthPoints;
public:
	Health(const short healthPoints = 3);
	short getHealthPoints() const;
	void reduceHealthPoints();
	bool isAlive() const;
	~Health();
};

