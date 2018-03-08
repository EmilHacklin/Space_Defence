#pragma once
#include"Player.h"
#include"Wave.h"
#include"Projectile.h"

const sf::Vector2f BACKGROUNDIMAGESIZE = sf::Vector2f(2560.0, 1440.0);

class Game : public sf::Transformable ,public sf::Drawable
{
private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundImage;
	sf::Vector2f scale;
	sf::Clock lockalClock;
	int randomNr;
	const float TIMEDELAY = 1;
	const int DEAFULTNROFWAVES = 3;
	Player player;
	Projectile *projectiles;
	Wave *waves;
	const int NROFPROJECTILES = 20;
	int nrOfWaves;
	int nrOfRounds;
	static void increseSpeed();
	bool isWavesDestroyed() const;
	bool havePlayerCollided() const;
	void newWaves();
public:
	Game() throw(...);
	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	unsigned int getNrOfRounds() const;
	bool isGameOver() const;
	~Game();
};

