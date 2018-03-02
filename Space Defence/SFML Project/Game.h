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
	Player player;
	Projectile *projectiles;
	Wave *waves;
	const int NROFPROJECTILES = 20;
	int nrOfWaves;
	int nrOfRounds;
	static void increseSpeed();
	bool isWavesDestroyed() const;
	void newWaves();
public:
	Game(int nrOfWaves = 3) throw(...);
	virtual void update();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	unsigned int getNrOfRounds() const;
	bool isGameOver() const;
	~Game();
};

