#include "Projectile.h"

Projectile::Projectile(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale) :
	MovingObject(texture, sizeOfKeyFrame, position, scale)
{
}

Projectile::Projectile(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const sf::Vector2f scale) :
	MovingObject(filePath, sizeOfKeyFrame, position, scale)
{
}

Projectile::Projectile(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, position, scale)
{
}

Projectile::Projectile(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const sf::Vector2f scale) :
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, position, scale)
{
}

Projectile::Projectile(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scale)
{
}

Projectile::Projectile(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scale)
{
}

Projectile::Projectile(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(texture, sizeOfKeyFrame, position, scaleX, scaleY)
{
}

Projectile::Projectile(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(filePath, sizeOfKeyFrame, position, scaleX, scaleY)
{
}

Projectile::Projectile(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, positionX, positionY, scale)
{
}

Projectile::Projectile(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const sf::Vector2f scale) :
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, positionX, positionY, scale)
{
}

Projectile::Projectile(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY) :
	MovingObject(texture, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
}

Projectile::Projectile(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float positionX, const float positionY, const float scaleX, const float scaleY) :
	MovingObject(filePath, sizeOfKeyFrame, positionX, positionY, scaleX, scaleY)
{
}

Projectile::Projectile(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, position, scaleX, scaleY)
{
}

Projectile::Projectile(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f position, const float scaleX, const float scaleY) :
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, position, scaleX, scaleY)
{
}

Projectile::Projectile(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY) :
	MovingObject(texture, keyFrameWidth, keyFrameHeight, positionX, positionY, scaleX, scaleY)
{
}

Projectile::Projectile(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float positionX, const float positionY, const float scaleX, const float scaleY) :
	MovingObject(filePath, keyFrameWidth, keyFrameHeight, positionX, positionY, scaleX, scaleY)
{
}

Projectile::Projectile(const Projectile &originalProjectile) :
	MovingObject(originalProjectile)
{
}

Projectile & Projectile::operator=(const Projectile &originalProjectile)
{
	if (&originalProjectile != this)
	{
		MovingObject::operator=(originalProjectile);
	}
	return *this;
}

bool Projectile::isActive() const
{
	if (this->getPosition().y > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Projectile::setPosition(const sf::Vector2f position) throw(...)
{
	if (position.x < 0 || position.x > windowSize.x || position.y < 0 || position.y > windowSize.y)
	{
		throw "Exception: Invalid position";
	}
	else
	{
		this->setPosition(position);
	}
}

void Projectile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	MovingObject::draw(target, states);
}

void Projectile::update()
{
	this->move(0, 1, this->SPEEDMULTIPLIER);
}

Projectile::~Projectile()
{
	cout << "Deleting Projectile" << endl;
}
