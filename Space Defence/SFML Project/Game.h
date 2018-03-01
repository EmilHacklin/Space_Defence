#pragma once
#include"Player.h"

const sf::Vector2f BACKGROUNDIMAGESIZE = sf::Vector2f(2560.0, 1440.0);

class Game : public sf::Transformable ,public sf::Drawable
{
private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundImage;
	sf::Vector2f scale;
	Player player;
	//MovingObject *wave;
	unsigned int nrOfRounds;
	static void increseSpeed();
	bool isWaveDestroyed() const;
	void newWave();
public:
	Game() throw(...);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	unsigned int getNrOfRounds() const;
	bool isGameOver() const;
	~Game();
};

