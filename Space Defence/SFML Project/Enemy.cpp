#include "Enemy.h"

Enemy::Enemy(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale):
	MovingObject(texture, sizeOfKeyFrame, position, scale)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale) :
	MovingObject(filePath, sizeOfKeyFrame, position, scale)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, position, scale)
{
	this->health;
	this->localClock;
}

Enemy::Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale) :
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, position, scale)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scale)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scale)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(texture, sizeOfKeyFrame, position, scaleX, scaleY)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(filePath, sizeOfKeyFrame, position, scaleX, scaleY)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, positionX, positionY, scale)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, positionX, positionY, scale)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY) :
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY) :
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, position, scaleX, scaleY)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, position, scaleX, scaleY)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, positionX, positionY, scaleX, scaleY)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY):
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, positionX, positionY, scaleX, scaleY)
{
	this->health = Health(1);
	this->localClock;
}

Enemy::Enemy(const Enemy &originalEnemy):
	MovingObject(originalEnemy)
{
	this->health = originalEnemy.health;
	this->localClock = originalEnemy.localClock;
}

Enemy & Enemy::operator=(const Enemy &originalEnemy)
{
	if (&originalEnemy != this)
	{
		MovingObject::operator=(originalEnemy);
		this->health = originalEnemy.health;
		this->localClock = originalEnemy.localClock;
	}
	return *this;
}

bool Enemy::hasCollisionOccurred(sf::FloatRect boundingBox) const
{
	if (boundingBox.intersects(this->getGlobalBoundingBox()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Enemy::hasCollisionOccurred(const MovingObject & otherMovingObject) const
{
	if (this->intersects(otherMovingObject))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Enemy::hasCollisionOccurred(const MovingObject & otherMovingObject, const sf::Vector2i direction) const
{
	sf::FloatRect otherGlobalBoundingBox = otherMovingObject.getGlobalBoundingBox();
	if (direction.x == -1)
	{
		if ((otherGlobalBoundingBox.left + otherGlobalBoundingBox.width > this->getGlobalBoundingBox().left)
			&& (otherGlobalBoundingBox.left < this->getGlobalBoundingBox().left + this->getGlobalBoundingBox().width)
			&& (otherGlobalBoundingBox.top + otherGlobalBoundingBox.height > this->getGlobalBoundingBox().top)
			&& (otherGlobalBoundingBox.top < this->getGlobalBoundingBox().top + this->getGlobalBoundingBox().height))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (direction.x == 1)
	{
		if ((otherGlobalBoundingBox.left + otherGlobalBoundingBox.width < this->getGlobalBoundingBox().left)
			&& (otherGlobalBoundingBox.left < this->getGlobalBoundingBox().left)
			&& (otherGlobalBoundingBox.top + otherGlobalBoundingBox.height > this->getGlobalBoundingBox().top)
			&& (otherGlobalBoundingBox.top < this->getGlobalBoundingBox().top + this->getGlobalBoundingBox().height))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (direction.y == -1)
	{

		if ((otherGlobalBoundingBox.left + otherGlobalBoundingBox.width > this->getGlobalBoundingBox().left)
			&& (otherGlobalBoundingBox.left < this->getGlobalBoundingBox().left + this->getGlobalBoundingBox().width)
			&& (otherGlobalBoundingBox.top + otherGlobalBoundingBox.height < this->getGlobalBoundingBox().top)
			&& (otherGlobalBoundingBox.top > this->getGlobalBoundingBox().top + this->getGlobalBoundingBox().height))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	return false;
}

void Enemy::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	MovingObject::draw(target, states);
}

void Enemy::update()
{
	this->animation();
}

void Enemy::update(sf::Vector2i direction)
{
	this->move(direction , this->SPEEDMULTIPLIER);
	this->animation();
}

void Enemy::animation()
{
	if (this->localClock.getElapsedTime().asSeconds() >= this->TIMEDELAY)
	{
		sf::IntRect keyFrame = this->getKeyFrameRect();
		if (keyFrame.left == keyFrame.width * (this->NROFKEYFRAMES - 1))
		{
			this->setKeyFrameRect(sf::IntRect(0, 0, keyFrame.width, keyFrame.height));
		}
		else
		{
			this->setKeyFrameRect(sf::IntRect(keyFrame.left + keyFrame.width, keyFrame.top, keyFrame.width, keyFrame.height));
		}
		this->localClock.restart();
	}
}

Enemy::~Enemy()
{
	cout << "Deleting Enemy" << endl;
}
