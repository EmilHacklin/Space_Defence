#include<iostream>
#include<crtdbg.h>
#include"Game.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	try
	{
		windowSize = sf::Vector2u(1200, 800);
		sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Space Defense", sf::Style::Close);
		Game game;
		MovingObject::resetGlobalClock();
		while (window.isOpen() || !game.isGameOver())
		{
			window.clear(sf::Color());

			game.update();
			window.draw(game);

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
	catch (char *exepString)
	{
		cout << exepString << endl;
		cin.get();
		return -1;
	}
}