#include<SFML\System.hpp>
#include <SFML/Graphics.hpp>
#include<thread>
#include<iostream>

using namespace std;
using namespace sf;

void renderingThread(RenderWindow* window)
{
	// the rendering loop
	while (window->isOpen())
	{
		// draw...

		// end the current frame
		window->display();
	}
}


int main()
{
	// create the window
	RenderWindow window(VideoMode(800, 600), "My window");

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(Color::Black);

		// draw everything here...
		// window.draw(...);

		// end the current frame
		window.display();
	}
	//multi threaded drawing
	window.create(VideoMode(800, 600), "My window");
	// deactivate its OpenGL context
	window.setActive(false);

	// launch the rendering thread
	thread thread(renderingThread, &window);

	// the event/logic/whatever loop
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(Color::Green);

		// draw everything here...
		// window.draw(...);

		thread.join();
		// end the current frame
		window.display();
	}

	return 0;
}