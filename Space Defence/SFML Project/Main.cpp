#include<iostream>
#include<crtdbg.h>
#include"Game.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Projectile* *projectileTest = new Projectile*[1];

	projectileTest[0] = new Projectile("../Resources/Projectile.png", PROJECTILEIMAGESIZE, 0.0, 0.0, 1, 1);

	Player playerTest;

	//playerTest = Player("../Resources/Player.png", PLAYERIMAGESIZE, 0, 0, 1, 1, projectileTest, 1);


	delete projectileTest[0];
	delete[] projectileTest;
	return 0;
	/*try
	{
		windowSize = sf::Vector2u(1200, 800);
		sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Space Defence", sf::Style::Close);
		Game game;
		while (!game.isGameOver() && window.isOpen())
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
	}*/
}