/*	Copyright © 2014 Sergey Makhonya, Vlad Kudelko
 *	licensed under the terms of the GNU General Public License (GPL) version 3
 */

#include <SFML\Graphics.hpp>
#include <UI\ui.h>
#include <UI\button.h>
#include <UI\input.h>
#include <UI\global.h>

#pragma comment (lib,"ui.lib")

#ifdef _DEBUG
	#pragma comment (lib,"sfml-system-d.lib")
	#pragma comment (lib,"sfml-window-d.lib")
	#pragma comment (lib,"sfml-graphics-d.lib")
#else
	#pragma comment (lib,"sfml-system.lib")
	#pragma comment (lib,"sfml-window.lib")
	#pragma comment (lib,"sfml-graphics.lib")
#endif

class ButtonEvent : public ui::IButton {
public:
	virtual void onClick(ui::Button *button) {
		button->setPosition(sf::Vector2f(	rand() % (int)(System::window->getSize().x - button->getSize().x),
											rand() % (int)(System::window->getSize().y - button->getSize().y)	));
	}
};

ui::Button button;

void init() {
	ButtonEvent *buttonEvent = new ButtonEvent();
	
	button.init();
	button.setCaption(L"Hello world!");
	button.setPosition(sf::Vector2f(15, 30));
	button.setEvent(buttonEvent);
}

void update() {
	button.update();
}

void resize(sf::Vector2u size) {
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	sf::RenderWindow window(sf::VideoMode(APP_WIDTH, APP_HEIGHT), APP_NAME);
	window.setFramerateLimit(60);
	System::window = &window;
	sf::View view(window.getDefaultView());
	Input::init();

	init();

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
			window.draw(button);
		}
		window.display();

		Input::flush();
	}

	return 0;
}