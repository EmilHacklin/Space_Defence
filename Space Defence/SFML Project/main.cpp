#include<iostream>
#include<SFML\System.hpp>
#include<SFML\Graphics.hpp>
#include"MovingObject.h"

using namespace std;

int main()
{
	sf::Vector2u windowSize = sf::Vector2u(800, 600);
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Space Defence", sf::Style::Close);
	MovingObject redBox, greenBox;
	sf::Vector2u sizeOfRed, sizeOfGreen;

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
		window.clear(sf::Color::Black);

		greenBox.update();
		MovingObject::resetClock();

		window.draw(redBox);
		window.draw(greenBox);

		sf::Event event;
		window.pollEvent(event);
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		window.display();
	}

	return 0;
}