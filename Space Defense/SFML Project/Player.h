#pragma once
#include"MovingObject.h"
#include"Health.h"

const sf::Vector2f PLAYERIMAGESIZE = sf::Vector2f(95, 151);

class Player :
	public MovingObject
{
private:
	Health health;
	int angle;
	sf::Clock localClock;
	const int NROFKEYFRAMES = 11;
	const double TIMEDELAY = 0.075;
public:
	Player(const sf::Texture &texture = sf::Texture(), const sf::Vector2f sizeOfKeyFrame = sf::Vector2f(), const sf::Vector2f position = sf::Vector2f(), const sf::Vector2f scale = sf::Vector2f(1.0, 1.0));
	Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale);
	Player(const sf::Texture &texture, const float KeyFrameWidth, const float KeyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale);
	Player(const string filePath, const float KeyFrameWidth, const float KeyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale);
	Player(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale);
	Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale);
	Player(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY);
	Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY);
	Player(const sf::Texture &texture, const float KeyFrameWidth, const float KeyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale);
	Player(const string filePath, const float KeyFrameWidth, const float KeyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale);
	Player(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Player(const sf::Texture &texture, const float KeyFrameWidth, const float KeyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY);
	Player(const string filePath, const float KeyFrameWidth, const float KeyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY);
	Player(const sf::Texture &texture, const float KeyFrameWidth, const float KeyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Player(const string filePath, const float KeyFrameWidth, const float KeyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY);
	Player(const Player &originalPlayer);
	Player& operator=(const Player &originalPlayer);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update();
	void input();
	void aniamtion(const int direction);
	bool isAlive() const;
	~Player();
};

