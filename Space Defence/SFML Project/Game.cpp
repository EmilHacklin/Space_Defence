#include "Game.h"

void Game::increseSpeed()
{
	MovingObject::increaseSpeed();
}

bool Game::isWavesDestroyed() const
{
	for (int i = 0; i < this->nrOfWaves; i++)
	{
		if (!this->waves[i].isWaveDestroyed())
		{
			return false;
		}
	}
	return true;
}

void Game::newWaves()
{
	delete[] this->waves;
	this->waves = new Wave[this->nrOfWaves];
	for (int i = 0; i < this->nrOfWaves; i++)
	{
		this->waves[i] = Wave("../Resources/Enemy.png", ENEMYIMAGESIZE, this->scale , 5 ,0.0);
	}
	
}

Game::Game()
{
	if (this->backgroundTexture.loadFromFile("../Resources/Background.png"))
	{
		srand(static_cast<int>(time(0)));
		this->backgroundImage = sf::Sprite(this->backgroundTexture);
		this->backgroundImage.setTextureRect(sf::IntRect(0, 0, static_cast<int>(BACKGROUNDIMAGESIZE.x), static_cast<int>(BACKGROUNDIMAGESIZE.y)));
		this->backgroundImage.setPosition(0, 0);
		this->scale = sf::Vector2f(windowSize.x / BACKGROUNDIMAGESIZE.x, windowSize.y / BACKGROUNDIMAGESIZE.y);
		this->backgroundImage.setScale(this->scale);
		this->randomNr = 0;//rand() % 3;
		this->lockalClock;
		MovingObject::resetSpeed();
		this->player = Player("../Resources/Player.png", PLAYERIMAGESIZE , static_cast<float>((windowSize.x - ((PLAYERIMAGESIZE.x * this->scale.x) / 2)) / 2.0), static_cast<float>(windowSize.y - (PLAYERIMAGESIZE.y * this->scale.y)), this->scale);
		this->nrOfWaves = 2;
		this->waves = new Wave[this->nrOfWaves];
		for (int i = 0; i < this->nrOfWaves; i++)
		{
			this->waves[i] = Wave("../Resources/Enemy.png", ENEMYIMAGESIZE, this->scale, 5, (ENEMYIMAGESIZE.y * i * this->scale.y));
		}
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

void Game::update()
{
	this->player.update();
	/*if (this->lockalClock.getElapsedTime().asSeconds() >= TIMEDELAY)
	{
		this->randomNr = rand() % 3;
		this->lockalClock.restart();
	}*/
	
	if (this->randomNr == 0)
	{
		this->waves[0].update(sf::Vector2i(-1, 0));
		if (this->nrOfWaves > 1)
		{
			for (int i = 1; i < this->nrOfWaves; i++)
			{
				this->waves[i].update(sf::Vector2i(-1, 0), this->waves[i - 1]);
			}
		}
	}
	else if (this->randomNr == 1)
	{
		this->waves[0].update(sf::Vector2i(1, 0));
		if (this->nrOfWaves > 1)
		{
			for (int i = 1; i < this->nrOfWaves; i++)
			{
				this->waves[i].update(sf::Vector2i(1, 0), this->waves[i - 1]);
			}
		}
	}
	else if (this->randomNr == 2)
	{
		this->waves[0].update(sf::Vector2i(0, 1));
		if (this->nrOfWaves > 1)
		{
			for (int i = 1; i < this->nrOfWaves; i++)
			{
				this->waves[i].update(sf::Vector2i(0, 1), this->waves[i - 1]);
			}
		}
	}
	MovingObject::resetGlobalClock();
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->backgroundImage, states);
	this->player.draw(target, states);
	for (int i = 0; i < this->nrOfWaves; i++)
	{
		this->waves[i].draw(target, states);
	}
}

unsigned int Game::getNrOfRounds() const
{
	return this->nrOfRounds;
}

bool Game::isGameOver() const
{
	return this->player.isAlive();
}

Game::~Game()
{
	delete[] this->waves;
}