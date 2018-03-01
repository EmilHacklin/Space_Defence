#include "Player.h"

Player::Player(const sf::Texture & texture, const sf::Vector2u sizeOfKeyFrame, const sf::Vector2f position):
	MovingObject(texture, sizeOfKeyFrame, position)
{
	this->angle = 0;
	this->localClock = sf::Clock();
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
		if (this->getPosition().x > 0)
		{
			this->moveSprite(sf::Vector2f(-this->speed * this->globalClock.getElapsedTime().asSeconds(), 0));
			this->aniamtion(-1);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (this->getPosition().x + this->getKeyFrameRect().width < windowSize.x)
		{
			this->moveSprite(sf::Vector2f(this->speed * this->globalClock.getElapsedTime().asSeconds(), 0));
			this->aniamtion(1);
		}
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
			keyFrameRect.top += keyFrameRect.height;
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

Player::~Player()
{
}