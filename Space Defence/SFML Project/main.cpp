#include<iostream>
#include<SFML\System.hpp>
#include<SFML\Graphics.hpp>
#include"Player.h"

using namespace std;

int main()
{
	windowSize = sf::Vector2u(800, 600);
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Space Defence", sf::Style::Close);
	Player greenBox;
	sf::Vector2u sizeOfGreen;

	if (!greenBox.setTexture("../Resources/Player.png", sf::Vector2u(95,151)))
	{
		return -1;
	}

	sizeOfGreen = sf::Vector2u(greenBox.getKeyFrameRect().width, greenBox.getKeyFrameRect().height);

	MovingObject::resetGlobalClock();
	while (window.isOpen())
	{
		window.clear(sf::Color::Black);

		greenBox.update();
		MovingObject::resetGlobalClock();

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