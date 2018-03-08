#include "Player.h"

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, sizeOfKeyFrame, position, scale)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, sizeOfKeyFrame, position, scale)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, keyFrameWidth, keyFrameHeight, position, scale)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, position, scale)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scale)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scale)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, sizeOfKeyFrame, position, scaleX, scaleY)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, sizeOfKeyFrame, position, scaleX, scaleY)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, keyFrameWidth, keyFrameHeight, positionX, positionY, scale)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, positionX, positionY, scale)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, keyFrameWidth, keyFrameHeight, position, scaleX, scaleY)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, position, scaleX, scaleY)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(texture, keyFrameWidth, keyFrameHeight, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY, Projectile* *projectiles, const int nrOfProjectiles):
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, positionX, positionY, scaleX, scaleY)
{
	this->health;
	this->projectiles = projectiles;
	this->nrOfProjectiles = nrOfProjectiles;
	this->angle = 0;
	this->localClock;
}

Player::Player(const Player &originalPlayer):
	MovingObject(originalPlayer)
{
	this->health = originalPlayer.health;
	this->projectiles = originalPlayer.projectiles;
	this->nrOfProjectiles = originalPlayer.nrOfProjectiles;
	this->angle = originalPlayer.angle;
	this->localClock = originalPlayer.localClock;
}

Player & Player::operator=(const Player &originalPlayer)
{
	if (&originalPlayer != this)
	{
		this->~Player();
		MovingObject::operator=(originalPlayer);
		this->health = originalPlayer.health;
		this->projectiles = originalPlayer.projectiles;
		this->nrOfProjectiles = originalPlayer.nrOfProjectiles;
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
		this->move(-1, 0, this->SPEEDMULTIPLIER);
		this->animation(-1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(1, 0, this->SPEEDMULTIPLIER);
		this->animation(1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		int i = 0;
		sf::Vector2f position = this->getPosition();
		while (this->projectiles[i]->isActive())
		{
			i++;
		}
		this->projectiles[i]->setPosition(position.x + ((PLAYERIMAGESIZE.x * this->getScale().x) / 2), position.y);
	} 
	else
	{
		this->animation(0);
	}
}

void Player::animation(const int direction)
{
	sf::IntRect keyFrameRect = this->getKeyFrameRect();
	if (direction == -1 && this->angle > -(this->NROFKEYFRAMES / 2) && this->localClock.getElapsedTime().asSeconds() > this->TIMEDELAY)
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
	else if (direction == 1 && this->angle < (this->NROFKEYFRAMES / 2) && this->localClock.getElapsedTime().asSeconds() > this->TIMEDELAY)
	{
		if (this->angle <= 0)
		{
			keyFrameRect.top = keyFrameRect.height * ((this->NROFKEYFRAMES / 2) + 1);
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