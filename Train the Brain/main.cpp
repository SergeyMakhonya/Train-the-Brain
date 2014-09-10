#include <SFML\Graphics.hpp>

#include "global.h"
#include "input.h"

#ifdef _DEBUG
	#pragma comment (lib,"sfml-system-d.lib")
	#pragma comment (lib,"sfml-window-d.lib")
	#pragma comment (lib,"sfml-graphics-d.lib")
#else
	#pragma comment (lib,"sfml-system.lib")
	#pragma comment (lib,"sfml-window.lib")
	#pragma comment (lib,"sfml-graphics.lib")
#endif

void update() {
}

void resize(sf::Vector2u size) {
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	sf::RenderWindow window(sf::VideoMode(1024, 768), APP_NAME);
	window.setFramerateLimit(60);

	sf::View view(window.getDefaultView());

	Input::init();

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
			else if (e.type == sf::Event::Resized) {
				sf::Vector2u windowSize = window.getSize();
				window.setView(view = sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(windowSize.x), static_cast<float>(windowSize.y))));
				resize(windowSize);
			}

			Input::analyseEvent(e);
		}

		update();

		window.clear(sf::Color::Black);
		{
			//window.draw();
		}
		window.display();

		Input::flush();
	}

	return 0;
}