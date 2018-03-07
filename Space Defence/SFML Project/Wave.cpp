#include "Wave.h"

Wave::Wave(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f scale, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(texture, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scale);
	}
}

Wave::Wave(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f scale, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(filePath, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), yOffset, scale);
	}
}

Wave::Wave(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f scale, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(texture, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scale);
	}
}

Wave::Wave(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f scale, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(filePath, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scale);
	}
}

Wave::Wave(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(texture, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0, scaleX, scaleY);
	}
}

Wave::Wave(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(filePath, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0, scaleX, scaleY);
	}
}

Wave::Wave(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];;
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(texture, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scaleX, scaleY);
	}
}

Wave::Wave(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...)
{
	if (nrOfEnemies < 0)
	{
		throw "Exception: Can not have negative nrOfEnemies";
	}
	else if (yOffset < 0 || yOffset > windowSize.y)
	{
		throw "Exception: Invalid yOffset";
	}
	this->nrOfEnemies = nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(filePath, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scaleX, scaleY);
	}
}

Wave::Wave(const Wave &originalWave)
{
	this->nrOfEnemies = originalWave.nrOfEnemies;
	this->enemies = new Enemy*[this->nrOfEnemies];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i] = new Enemy(*originalWave.enemies[i]);
	}
}

Wave & Wave::operator=(const Wave &originalWave)
{
	if (&originalWave != this)
	{
		this->nrOfEnemies = originalWave.nrOfEnemies;
		this->enemies = new Enemy*[this->nrOfEnemies];
		for (int i = 0; i < this->nrOfEnemies; i++)
		{
			this->enemies[i] = new Enemy(*originalWave.enemies[i]);
		}
	}
	return *this;
}

bool Wave::hasCollisionOccurred(MovingObject &otherMovingObject) const
{
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		if (this->enemies[i]->hasCollisionOccurred(otherMovingObject.getGlobalBoundingBox()))
		{
			return true;
		}
	}
	return false;
}

bool Wave::hasCollisionOccurred(MovingObject & otherMovingObject, const sf::Vector2i direction) const
{
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		if (this->enemies[i]->hasCollisionOccurred(otherMovingObject, direction))
		{
			return true;
		}
	}
	return false;
}

bool Wave::isWaveDestroyed() const
{
	if (this->nrOfEnemies == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Wave::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i]->draw(target, states);
	}
}

void Wave::update()
{
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i]->update();
	}
}

void Wave::update(const sf::Vector2i direction)
{
	if (this->nrOfEnemies > 0)
	{
		if (direction.x == -1)
		{
			this->enemies[0]->update(direction);
			if (this->nrOfEnemies > 2)
			{
				for (int i = 1; i < this->nrOfEnemies; i++)
				{
					if (!this->enemies[i]->intersects(*this->enemies[i - 1]))
					{
						this->enemies[i]->update(direction);
					}
					else
					{
						this->enemies[i]->update();
					}
				}
			}
			if (this->nrOfEnemies > 1 && !this->enemies[this->nrOfEnemies - 1]->intersects(*this->enemies[this->nrOfEnemies - 2]))
			{
				this->enemies[this->nrOfEnemies - 1]->update(direction);
			}
			else
			{
				this->enemies[this->nrOfEnemies - 1]->update();
			}
		}
		else if (direction.x == 1)
		{
			this->enemies[this->nrOfEnemies - 1]->update(direction);
			if (this->nrOfEnemies > 2)
			{
				for (int i = this->nrOfEnemies - 2; i > 0; i--)
				{
					if (!this->enemies[i]->intersects(*this->enemies[i + 1]))
					{
						this->enemies[i]->update(direction);
					}
					else
					{
						this->enemies[i]->update();
					}
				}
			}
			if (this->nrOfEnemies > 1 && !this->enemies[0]->intersects(*this->enemies[1]))
			{
				this->enemies[0]->update(direction);
			}
			else
			{
				this->enemies[0]->update();
			}
		}
		else if (direction.y == 1)
		{
			for (int i = 0; i < this->nrOfEnemies; i++)
			{
				this->enemies[i]->update(direction);
			}
		}
		else
		{
			for (int i = 0; i < this->nrOfEnemies; i++)
			{
				this->enemies[i]->update();
			}
		}
	}
}

void Wave::update(const sf::Vector2i direction, const Wave otherWave)
{
	if (this->nrOfEnemies > 0)
	{
		if (direction.x == -1)
		{
			if (!otherWave.hasCollisionOccurred(*this->enemies[this->nrOfEnemies - 1], direction))
			{
				this->enemies[0]->update(direction);
			}
			if (this->nrOfEnemies > 2)
			{
				for (int i = 1; i < this->nrOfEnemies; i++)
				{
					if (!this->enemies[i]->intersects(*this->enemies[i - 1]))
					{
						this->enemies[i]->update(direction);
					}
					else
					{
						this->enemies[i]->update();
					}
				}
			}
			if (this->nrOfEnemies > 1 && !otherWave.hasCollisionOccurred(*this->enemies[this->nrOfEnemies - 1], direction) && !this->enemies[this->nrOfEnemies - 1]->intersects(*this->enemies[this->nrOfEnemies - 2]))
			{
				this->enemies[this->nrOfEnemies - 1]->update(direction);
			}
			else
			{
				this->enemies[this->nrOfEnemies - 1]->update();
			}
		}
		else if (direction.x == 1)
		{
			if (!otherWave.hasCollisionOccurred(*this->enemies[this->nrOfEnemies - 1], direction))
			{
				this->enemies[this->nrOfEnemies - 1]->update(direction);
			}
			if (this->nrOfEnemies > 2)
			{
				for (int i = this->nrOfEnemies - 2; i > 0; i--)
				{
					if (!otherWave.hasCollisionOccurred(*this->enemies[i], direction) && !this->enemies[i]->intersects(*this->enemies[-i]))
					{
						this->enemies[i]->update(direction);
					}
					else
					{
						this->enemies[i]->update();
					}
				}
			}
			if (this->nrOfEnemies > 1 && !otherWave.hasCollisionOccurred(*this->enemies[0], direction) && !this->enemies[0]->intersects(*this->enemies[1]))
			{
				this->enemies[0]->update(direction);
			}
			else
			{
				this->enemies[0]->update();
			}
		}
		else if (direction.y == 1)
		{
			for (int i = 0; i < this->nrOfEnemies; i++)
			{
				if (!otherWave.hasCollisionOccurred(*this->enemies[i], direction))
				{
					this->enemies[i]->update(direction);
				}
			}
		}
		else
		{
			for (int i = 0; i < this->nrOfEnemies; i++)
			{
				this->enemies[i]->update();
			}
		}
	}
}

Wave::~Wave()
{
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		delete this->enemies[i];
	}
	delete[] this->enemies;
	cout << "Deleting Wave" << endl;
}
