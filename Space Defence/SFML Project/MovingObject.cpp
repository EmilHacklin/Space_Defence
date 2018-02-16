#include "MovingObject.h"


MovingObject::MovingObject(const Texture &texture, const Vector2f position)
{
	this->texture = texture;
	this->sprite = Sprite(this->texture);
	this->boundingBox = this->sprite.getGlobalBounds();
	this->sprite.setPosition(position);
	this->speed = 10;
}

float MovingObject::getPositionX() const
{
	Vector2f pos = this->sprite.getPosition();
	return pos.x;
}

float MovingObject::getPositionY() const
{
	Vector2f pos = this->sprite.getPosition();
	return pos.y;
}

Vector2f MovingObject::getPosition() const
{
	return this->sprite.getPosition();
}

Vector2f MovingObject::getSize() const
{
	Vector2f spriteSize(this->boundingBox.width, this->boundingBox.height);
	return spriteSize;
}

bool MovingObject::setTexture(const string filePath)
{
	if (this->texture.loadFromFile(filePath))
	{
		this->sprite = Sprite(this->texture);
		this->boundingBox = this->sprite.getGlobalBounds();
		return true;
	}
	return false;
}

void MovingObject::setPosition(const Vector2f position)
{
	this->sprite.setPosition(position);
}

void MovingObject::setPosition(const float positionX, const float positionY)
{
	this->sprite.setPosition(positionX, positionY);
}

void MovingObject::move(const Vector2i direction)
{
	if (direction.x == -1)
	{
		this->sprite.move(-this->speed, 0);
	}
	else if (direction.x == 1)
	{
		this->sprite.move(this->speed, 0);
	}
	else if (direction.y == -1)
	{
		this->sprite.move(0, -this->speed);
	}
	else if (direction.y == 1)
	{
		this->sprite.move(0, this->speed);
	}
}

void MovingObject::draw(RenderWindow & window) const
{
	window.draw(this->sprite);
}

void MovingObject::input(RenderWindow & window)
{
	Event event;
	window.pollEvent(event);
	Vector2u windowSize;
	switch (event.type)
	{
	case Event::KeyPressed:
		windowSize = window.getSize();
		if (event.key.code == Keyboard::Left)
		{
			if (this->getPositionX() > 0)
			{
				this->move(Vector2i(-1, 0));
			}
		}
		else if (event.key.code == Keyboard::Right)
		{
			if ((this->getPositionX() + this->boundingBox.width) < windowSize.x)
			{
				this->move(Vector2i(1, 0));
			}
		}
		else if (event.key.code == Keyboard::Up)
		{
			if (this->getPositionY() > 0)
			{
				this->move(Vector2i(0, -1));
			}
		}
		else if (event.key.code == Keyboard::Down)
		{
			if ((this->getPositionY() + this->boundingBox.height) < windowSize.y)
			{
				this->move(Vector2i(0, 1));
			}
		}
	default:
		break;
	}
}


MovingObject::~MovingObject()
{
	cout << "Deleting object" << endl;
}
