#pragma once
#include "MovingObject.h"

class Player :
	public MovingObject
{
private:
	int angle;
	sf::Clock localClock;
public:
	Player(const sf::Texture &texture = sf::Texture(), const sf::Vector2u sizeOfKeyFrame = sf::Vector2u(), const sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update();
	void input();
	~Player();
};

