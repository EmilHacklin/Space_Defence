#pragma once
#include"Enemy.h"

class Wave : public sf::Transformable, public sf::Drawable
{
private:
	Enemy* *enemies;
	int nrOfEnemies;
public:
	Wave(const sf::Texture &texture = sf::Texture(), const sf::Vector2f sizeOfKeyFrame = sf::Vector2f(), const sf::Vector2f scale = sf::Vector2f(1.0, 1.0), const int nrOfEnemies = 5, const float yOffset = 0) throw(...);
	Wave(const string filePath, const sf::Vector2f sizeOfKeyFrame, const sf::Vector2f scale, const int nrOfEnemies, const float yOffset) throw(...);
	Wave(const sf::Texture &texture, const sf::Vector2f sizeOfKeyFrame, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...);
	Wave(const string filePath, const sf::Vector2f sizeOfKeyFrame, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...);
	Wave(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f scale, const int nrOfEnemies, const float yOffset) throw(...);
	Wave(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const sf::Vector2f scale, const int nrOfEnemies, const float yOffset) throw(...);
	Wave(const sf::Texture &texture, const float keyFrameWidth, const float keyFrameHeight, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...);
	Wave(const string filePath, const float keyFrameWidth, const float keyFrameHeight, const float scaleX, const float scaleY, const int nrOfEnemies, const float yOffset) throw(...);
	Wave(const Wave &originalWave);
	Wave& operator=(const Wave &originalWave);
	bool isWaveDestroyed() const;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update();
	~Wave();
};

