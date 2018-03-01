#include "Game.h"



void Game::increseSpeed()
{
	MovingObject::increaseSpeed();
}

bool Game::isWaveDestroyed() const
{
	return false;
}

void Game::newWave()
{
	//delete this->wave;
	//this->wave = new MovingObject;
}

Game::Game()
{
	if (this->backgroundTexture.loadFromFile("../Resources/Background.png"))
	{
		this->backgroundImage = sf::Sprite(this->backgroundTexture);
		this->backgroundImage.setTextureRect(sf::IntRect(0, 0, static_cast<int>(BACKGROUNDIMAGESIZE.x), static_cast<int>(BACKGROUNDIMAGESIZE.y)));
		this->backgroundImage.setPosition(0, 0);
		this->scale = sf::Vector2f(windowSize.x / BACKGROUNDIMAGESIZE.x, windowSize.y / BACKGROUNDIMAGESIZE.y);
		this->backgroundImage.setScale(this->scale);
		this->player = Player("../Resources/Player.png", PLAYERIMAGESIZE , static_cast<float>((windowSize.x - ((PLAYERIMAGESIZE.x * this->scale.x) / 2)) / 2.0), static_cast<float>(windowSize.y - (PLAYERIMAGESIZE.y * this->scale.y)), this->scale);
		//this->wave = new MovingObject(enemyTexture, sf::Vector2u(64, 64));
	}
	else
	{
		throw "Exception: Could not load texture";
	}
}

void Game::update()
{
	this->player.update();
	/*this->wave->update();*/
	this->player.resetGlobalClock();
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->backgroundImage, states);
	this->player.draw(target, states);
	/*this->wave->draw(target, states);*/
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
	//delete this->wave;
}
