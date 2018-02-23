#include "MovingObject.h"

sf::Vector2u  windowSize;
float MovingObject::speed = 200;
sf::Clock MovingObject::globalClock;

MovingObject::MovingObject(const sf::Texture &texture, const sf::Vector2u sizeOfKeyFrame,const sf::Vector2f position)
{
	this->texture = texture;
	this->sprite = sf::Sprite(this->texture);
	this->keyFrameRect = sf::IntRect(0, 0, sizeOfKeyFrame.x, sizeOfKeyFrame.y);
	this->sprite.setTextureRect(this->keyFrameRect);
	this->angle = 0;
	this->sprite.setPosition(position);
	this->globalClock;
}

sf::Vector2f MovingObject::getPosition() const
{
	return this->sprite.getPosition();
}

sf::Vector2u MovingObject::getSizeOfTexture() const
{
	return this->texture.getSize();
}

sf::Vector2u MovingObject::getSizeOfKeyFrame() const
{
	return sf::Vector2u(this->keyFrameRect.width, this->keyFrameRect.height);
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
	globalClock.restart();
}

void MovingObject::move(const sf::Vector2i direction)
{
	
	if (direction.x == -1 && this->canMoveLeft())
	{
		this->sprite.move(-this->speed*this->globalClock.getElapsedTime().asSeconds(), 0);
	}
	else if (direction.x == 1 && this->canMoveRight())
	{
		this->sprite.move(this->speed*this->globalClock.getElapsedTime().asSeconds(), 0);
	}
}

bool MovingObject::canMoveLeft() const
{
	if (this->sprite.getPosition().x > 0)
	{
		return true;
	}
	return false;
}

bool MovingObject::canMoveRight() const
{
	if (this->sprite.getPosition().x + this->keyFrameRect.width < windowSize.x)
	{
		return true;
	}
	return false;
}

void MovingObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}

void MovingObject::update()
{
	this->input();
}

void MovingObject::input()
{
	sf::Time localTime = this->localClock.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(sf::Vector2i(-1, 0));
		if (localTime.asSeconds() > 0.075 && this->angle > -5)
		{
			if (this->angle >= 0)
			{
				this->keyFrameRect.top = this->keyFrameRect.height;
				this->angle = -1;
			}
			else
			{
				this->keyFrameRect.top += this->keyFrameRect.height;
				this->angle--;
			}
			this->sprite.setTextureRect(this->keyFrameRect);
			this->localClock.restart();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(sf::Vector2i(1, 0));
		if (localTime.asSeconds() > 0.075 && this->angle < 5)
		{
			if (this->angle <= 0)
			{
				this->keyFrameRect.top = this->keyFrameRect.height * 6;
				this->angle = 1;
			}
			else
			{
				this->keyFrameRect.top += this->keyFrameRect.height;
				this->angle++;
			}
			this->sprite.setTextureRect(this->keyFrameRect);
			this->localClock.restart();
		}
	}
	else if (this->angle != 0 && localTime.asSeconds() > 0.05)
	{
		if (this->angle == 1)
		{
			this->keyFrameRect.top = 0;
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
			this->keyFrameRect.top -= this->keyFrameRect.height;
		}
		this->sprite.setTextureRect(this->keyFrameRect);
		this->localClock.restart();
	}
}

MovingObject::~MovingObject()
{
	cout << "Deleting object" << endl;
}
