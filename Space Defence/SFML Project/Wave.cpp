#include "Wave.h"

Wave::Wave(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f scale, const int nrOfEnemies)
{
	this->nrOfEnemies = nrOfEnemies;
	this->capacity = nrOfEnemies;
	this->enemies = new Enemy*[this->capacity];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i - 1] = new Enemy(texture, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scale);
	}
	this->localClock;
}

Wave::Wave(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f scale, const int nrOfEnemies)
{
	this->nrOfEnemies = nrOfEnemies;
	this->capacity = nrOfEnemies;
	this->enemies = new Enemy*[this->capacity];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i - 1] = new Enemy(filePath, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scale);
	}
	this->localClock;
}

Wave::Wave(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f scale, const int nrOfEnemies)
{
	this->nrOfEnemies = nrOfEnemies;
	this->capacity = nrOfEnemies;
	this->enemies = new Enemy*[this->capacity];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i - 1] = new Enemy(texture, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scale);
	}
	this->localClock;
}

Wave::Wave(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f scale, const int nrOfEnemies)
{
	this->nrOfEnemies = nrOfEnemies;
	this->capacity = nrOfEnemies;
	this->enemies = new Enemy*[this->capacity];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i - 1] = new Enemy(filePath, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scale);
	}
	this->localClock;
}

Wave::Wave(const sf::Texture & texture, const sf::Vector2f sizeOfKeyFrame, const float scaleX, const float scaleY, const int nrOfEnemies)
{
	this->nrOfEnemies = nrOfEnemies;
	this->capacity = nrOfEnemies;
	this->enemies = new Enemy*[this->capacity];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i - 1] = new Enemy(texture, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0, scaleX, scaleY);
	}
	this->localClock;
}

Wave::Wave(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float scaleX, const float scaleY, const int nrOfEnemies)
{
	this->nrOfEnemies = nrOfEnemies;
	this->capacity = nrOfEnemies;
	this->enemies = new Enemy*[this->capacity];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i - 1] = new Enemy(filePath, sizeOfKeyFrame, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0, scaleX, scaleY);
	}
	this->localClock;
}

Wave::Wave(const sf::Texture & texture, const float keyFrameWidth, const float keyFrameHeight, const float scaleX, const float scaleY, const int nrOfEnemies)
{
	this->nrOfEnemies = nrOfEnemies;
	this->capacity = nrOfEnemies;
	this->enemies = new Enemy*[this->capacity];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i - 1] = new Enemy(texture, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scaleX, scaleY);
	}
	this->localClock;
}

Wave::Wave(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float scaleX, const float scaleY, const int nrOfEnemies)
{
	this->nrOfEnemies = nrOfEnemies;
	this->capacity = nrOfEnemies;
	this->enemies = new Enemy*[this->capacity];
	for (int i = 0; i < this->nrOfEnemies; i++)
	{
		this->enemies[i - 1] = new Enemy(filePath, keyFrameWidth, keyFrameHeight, static_cast<float>(i * (windowSize.x / this->nrOfEnemies)), 0.0, scaleX, scaleY);
	}
	this->localClock;
}

Wave::Wave(const Wave &originalWave)
{
	this->nrOfEnemies = originalWave.nrOfEnemies;
	this->localClock = originalWave.localClock;
}

Wave & Wave::operator=(const Wave &originalWave)
{
	if (&originalWave != this)
	{
		this->nrOfEnemies = originalWave.nrOfEnemies;
		this->localClock = originalWave.localClock;
	}
	return *this;
}

Wave::~Wave()
{
}
