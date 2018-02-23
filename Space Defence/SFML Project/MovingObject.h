#pragma once
#include<SFML\System.hpp>
#include<SFML\Graphics.hpp>
#include<iostream>

using namespace std;

extern sf::Vector2u windowSize;

class MovingObject : public sf::Drawable
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect keyFrameRect;
public:
	static sf::Clock globalClock;
	static float speed;
	MovingObject(const sf::Texture &texture = sf::Texture(), const sf::Vector2u sizeOfKeyFrame = sf::Vector2u(), const sf::Vector2f position = sf::Vector2f(0.0f, 0.0f));
	sf::Vector2f getPosition() const;
	sf::Vector2u getSizeOfTexture() const;
	sf::IntRect getKeyFrameRect() const;
	bool setTexture(const string filePath, const sf::Vector2u sizeOfKeyFrame);
	void setKeyFrameRect(const sf::IntRect keyFrameRect);
	void setPosition(const sf::Vector2f position);
	void setPosition(const float positionX, const float positionY);
	static void resetGlobalClock();
	void moveSprite(const sf::Vector2f offset);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void update() = 0;
	~MovingObject();
};

