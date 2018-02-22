#include "MovingObject.h"

float MovingObject::speed = 200;
sf::Clock MovingObject::clock;

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

void MovingObject::move(const sf::Vector2i direction)
{
	if (direction.x == -1 && this->sprite.getPosition().x > 0)
	{
		this->sprite.move(-this->speed*this->clock.getElapsedTime().asSeconds(), 0);
	}
	else if (direction.x == 1 && (this->sprite.getPosition().x + this->keyFrameRect.width))// < windowSize.x)
	{
		this->sprite.move(this->speed*this->clock.getElapsedTime().asSeconds(), 0);
	}
}

void MovingObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}

void MovingObject::update()
{
	this->input();
	this->clock.restart();
}

void MovingObject::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(sf::Vector2i(-1, 0));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(sf::Vector2i(1, 0));
	}
}

//void MovingObject::input(sf::RenderWindow & window)
//{
//	sf::Event event;
//	window.pollEvent(event);
//	sf::Vector2u windowSize;
//	sf::Vector2f pos;
//	switch (event.type)
//	{
//	case sf::Event::KeyPressed:
//		windowSize = window.getSize();
//		pos = this->sprite.getPosition();
//		if (event.key.code == sf::Keyboard::Left)
//		{
//			if (pos.x > 0)
//			{
//				this->move(sf::Vector2i(-1, 0));
//			}
//		}
//		else if (event.key.code == sf::Keyboard::Right)
//		{
//			if ((pos.x + this->keyFrameRect.width) < windowSize.x)
//			{
//				this->move(sf::Vector2i(1, 0));
//			}
//		}
//		else if (event.key.code == sf::Keyboard::Up)
//		{
//			if (pos.y > 0)
//			{
//				this->move(sf::Vector2i(0, -1));
//			}
//		}
//		else if (event.key.code == sf::Keyboard::Down)
//		{
//			if ((pos.y + this->keyFrameRect.height) < windowSize.y)
//			{
//				this->move(sf::Vector2i(0, 1));
//			}
//		}
//	default:
//		break;
//	}
//}


MovingObject::~MovingObject()
{
	cout << "Deleting object" << endl;
}
