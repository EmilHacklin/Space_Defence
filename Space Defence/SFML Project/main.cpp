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
	Vector2f sizeOfRed, sizeOfGreen;

	if (!redBox.setTexture("../Resources/Red.png") || !greenBox.setTexture("../Resources/Green.png"))
	{
		return -1;
	}

	sizeOfRed = redBox.getSize();
	sizeOfGreen = greenBox.getSize();

	redBox.setPosition((float)(400 - (sizeOfRed.x / 2)), (float)(300 - (sizeOfRed.y / 2)));
	greenBox.setPosition((float)(400 - (sizeOfGreen.x / 2)), (float)(100 - (sizeOfGreen.y / 2)));

	while (window.isOpen())
	{
		window.clear(Color::Black);

		redBox.draw(window);
		greenBox.draw(window);

		greenBox.input(window);

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