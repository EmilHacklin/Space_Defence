#include "Player.h"

Player::Player(const sf::Texture & texture, const sf::Vector2u sizeOfKeyFrame, const sf::Vector2f position):
	MovingObject(texture, sizeOfKeyFrame, position)
{
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
			if (this->localClock.restart().asSeconds() > 0.075 && this->angle > -5)
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
			}
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (this->getPosition().x + this->getKeyFrameRect().width < windowSize.x)
		{
			this->setPosition(sf::Vector2f(this->speed * this->globalClock.getElapsedTime().asSeconds(), 0));
			if (this->localClock.restart().asSeconds() > 0.075 && this->angle < 5)
			{
				if (this->angle <= 0)
				{
					keyFrameRect.top = keyFrameRect.height * 6;
					this->angle = 1;
				}
				else
				{
					keyFrameRect.top += keyFrameRect.height;
					this->angle++;
				}
				this->setKeyFrameRect(keyFrameRect);
			}
		}
	}
	else if (this->angle != 0 && this->localClock.restart().asSeconds() > 0.05)
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
	}
}

Player::~Player()
{
}