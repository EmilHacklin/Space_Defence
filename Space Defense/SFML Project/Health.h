#pragma once
class Health
{
private:
	short healthPoints;
public:
	Health(const short healthPoints = 3);
	Health(const Health &originalHealth);
	Health& operator=(const Health &originalHealth);
	short getHealthPoints() const;
	void reduceHealthPoints();
	bool isAlive() const;
	~Health();
};

