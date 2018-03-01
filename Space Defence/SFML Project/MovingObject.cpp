#include "MovingObject.h"

sf::Vector2u  windowSize;
float MovingObject::speed = 200;
sf::Clock MovingObject::globalClock = sf::Clock();

MovingObject::MovingObject(const sf::Texture &texture, const sf::Vector2u sizeOfKeyFrame,const sf::Vector2f position)
{
	this->texture = texture;
	this->sprite = sf::Sprite(this->texture);
	this->keyFrameRect = sf::IntRect(0, 0, sizeOfKeyFrame.x, sizeOfKeyFrame.y);
	this->sprite.setTextureRect(this->keyFrameRect);
	this->sprite.setPosition(position);
}

sf::Vector2f MovingObject::getPosition() const
{
	return this->sprite.getPosition();
}

sf::Vector2u MovingObject::getSizeOfTexture() const
{
	return this->texture.getSize();
}

sf::IntRect MovingObject::getKeyFrameRect() const
{
	return this->keyFrameRect;
}

bool MovingObject::setTexture(const string filePath, const sf::Vector2u sizeOfKeyFrame)
{
	if (this->texture.loadFromFile(filePath))
	{
		sf::Vector2f pos = this->sprite.getPosition();
		this->sprite = sf::Sprite(this->texture);
		this->setPosition(pos);
		this->keyFrameRect = sf::IntRect(0, 0, sizeOfKeyFrame.x, sizeOfKeyFrame.y);
		this->sprite.setTextureRect(this->keyFrameRect);
		return true;
	}
	return false;
}

void MovingObject::setKeyFrameRect(const sf::IntRect keyFrameRect)
{
	this->keyFrameRect = keyFrameRect;
	this->sprite.setTextureRect(this->keyFrameRect);
}

void MovingObject::setPosition(const sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

void MovingObject::setPosition(const float positionX, const float positionY)
{
	this->sprite.setPosition(positionX, positionY);
}

void MovingObject::resetGlobalClock()
{
	MovingObject::globalClock.restart();
}

void MovingObject::moveSprite(const sf::Vector2f offset)
{
	this->sprite.move(offset);
}

void MovingObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}

MovingObject::~MovingObject()
{
	cout << "Deleting MovingObject" << endl;
}