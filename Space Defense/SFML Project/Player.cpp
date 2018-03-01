#include "Player.h"

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale):
	MovingObject(texture, sizeOfKeyFrame, position, scale)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale):
	MovingObject(filePath, sizeOfKeyFrame, position, scale)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const sf::Texture & texture, const float KeyFrameWidth, const float KeyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale):
	MovingObject(texture, KeyFrameWidth, KeyFrameHeight, position, scale)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const string filePath, const float KeyFrameWidth, const float KeyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale):
	MovingObject(filePath, KeyFrameWidth, KeyFrameHeight, position, scale)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale):
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scale)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale):
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scale)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY):
	MovingObject(texture, sizeOfKeyFrame, position, scaleX, scaleY)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY):
	MovingObject(filePath, sizeOfKeyFrame, position, scaleX, scaleY)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const sf::Texture & texture, const float KeyFrameWidth, const float KeyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale):
	MovingObject(texture, KeyFrameWidth, KeyFrameHeight, positionX, positionY, scale)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const string filePath, const float KeyFrameWidth, const float KeyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale):
	MovingObject(filePath, KeyFrameWidth, KeyFrameHeight, positionX, positionY, scale)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY):
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY):
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const sf::Texture & texture, const float KeyFrameWidth, const float KeyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY):
	MovingObject(texture, KeyFrameWidth, KeyFrameHeight, position, scaleX, scaleY)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const string filePath, const float KeyFrameWidth, const float KeyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY):
	MovingObject(filePath, KeyFrameWidth, KeyFrameHeight, position, scaleX, scaleY)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const sf::Texture & texture, const float KeyFrameWidth, const float KeyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY):
	MovingObject(texture, KeyFrameWidth, KeyFrameHeight, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const string filePath, const float KeyFrameWidth, const float KeyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY):
	MovingObject(filePath, KeyFrameWidth, KeyFrameHeight, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->angle = 0;
	this->localClock = sf::Clock();
}

Player::Player(const Player &originalPlayer):
	MovingObject(originalPlayer)
{
	this->health = originalPlayer.health;
	this->angle = originalPlayer.angle;
	this->localClock = originalPlayer.localClock;
}

Player & Player::operator=(const Player &originalPlayer)
{
	if (&originalPlayer != this)
	{
		MovingObject::operator=(originalPlayer);
		this->health = originalPlayer.health;
		this->angle = originalPlayer.angle;
		this->localClock = originalPlayer.localClock;
	}
	return *this;
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	MovingObject::draw(target, states);
}

void Player::update()
{
	this->input();
}

void Player::input()
{
	sf::IntRect keyFrameRect = this->getKeyFrameRect();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(-1, 0);
		this->aniamtion(-1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(1, 0);
		this->aniamtion(1);
	}
	else
	{
		this->aniamtion(0);
	}
}

void Player::aniamtion(const int direction)
{
	sf::IntRect keyFrameRect = this->getKeyFrameRect();
	if (direction == -1 && this->angle > -(NROFKEYFRAMES / 2) && this->localClock.getElapsedTime().asSeconds() > TIMEDELAY)
	{
		if (this->angle >= 0)
		{
			keyFrameRect.top = keyFrameRect.height;
			this->angle = -1;
		}
		else
		{
			keyFrameRect.top += keyFrameRect.height;
			this->angle--;
		}
		this->setKeyFrameRect(keyFrameRect);
		this->localClock.restart();
	}
	else if (direction == 1 && this->angle < (NROFKEYFRAMES / 2) && this->localClock.getElapsedTime().asSeconds() > TIMEDELAY)
	{
		if (this->angle <= 0)
		{
			keyFrameRect.top = keyFrameRect.height * ((NROFKEYFRAMES / 2) + 1);
			this->angle = 1;
		}
		else
		{
			keyFrameRect.top += keyFrameRect.height;
			this->angle++;
		}
		this->setKeyFrameRect(keyFrameRect);
		this->localClock.restart();
	}
	else if (direction == 0 && this->angle != 0 && this->localClock.getElapsedTime().asSeconds() > TIMEDELAY)
	{
		if (this->angle == 1)
		{
			keyFrameRect.top = 0;
			this->angle--;
		}
		else
		{
			if (this->angle < 0)
			{
				this->angle++;
			}
			else if (this->angle > 0)
			{
				this->angle--;
			}
			keyFrameRect.top -= keyFrameRect.height;
		}
		this->setKeyFrameRect(keyFrameRect);
		this->localClock.restart();
	}
}

bool Player::isAlive() const
{
	return this->health.isAlive();
}

Player::~Player()
{
	cout << "Deleting Player" << endl;
}