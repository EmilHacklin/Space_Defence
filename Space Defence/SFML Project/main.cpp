#include<iostream>
#include<SFML\System.hpp>
#include<SFML\Graphics.hpp>
#include"MovingObject.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "My window", Style::Close);
	MovingObject redBox, greenBox;
	Vector2u sizeOfRed, sizeOfGreen;

	if (!redBox.setTexture("../Resources/Red.png", sf::Vector2u(50,50)) || !greenBox.setTexture("../Resources/Player.png", sf::Vector2u(95,151)))
	{
		return -1;
	}

	sizeOfRed = redBox.getSizeOfKeyFrame();
	sizeOfGreen = greenBox.getSizeOfKeyFrame();

	redBox.setPosition((float)(400 - (sizeOfRed.x / 2)), (float)(300 - (sizeOfRed.y / 2)));
	greenBox.setPosition((float)(400 - (sizeOfGreen.x / 2)), (float)(100 - (sizeOfGreen.y / 2)));

	while (window.isOpen())
	{
		window.clear(Color::Black);

		greenBox.update();

		window.draw(redBox);
		window.draw(greenBox);

		Event event;
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			window.close();
		}

		window.display();
	}

	return 0;
}