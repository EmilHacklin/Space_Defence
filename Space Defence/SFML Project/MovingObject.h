#pragma once
#include<SFML\System.hpp>
#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>

using namespace std;
using namespace sf;

class MovingObject
{
private:
	Sprite sprite;
	Texture texture;
	FloatRect boundingBox;
	float speed;
public:
	MovingObject(const Texture &texture = Texture(),const Vector2f position = Vector2f(0.0f, 0.0f));
	float getPositionX() const;
	float getPositionY() const;
	Vector2f getPosition() const;
	Vector2f getSize() const;
	bool setTexture(const string filePath);
	void setPosition(const Vector2f position);
	void setPosition(const float positionX, const float positionY);
	void move(const Vector2i direction);
	void draw(RenderWindow &window) const;
	void input(RenderWindow &window);
	~MovingObject();
};

