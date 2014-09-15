/*	Copyright © 2014 Sergey Makhonya, Vlad Kudelko
 *	licensed under the terms of the GNU General Public License (GPL) version 3
 */

#include <SFML\Graphics.hpp>
#include <UI\ui.h>
#include <UI\button.h>
#include <UI\textbox.h>
#include <UI\input.h>
#include <UI\global.h>
//#include <UI\res.h>

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

ui::Button button;
ui::Textbox textbox;

class ButtonEvent : public ui::IButton {
public:
	virtual void onClick(ui::Button *button) {
		/*button->setPosition(sf::Vector2f(	rand() % (int)(System::window->getSize().x - button->getSize().x),
											rand() % (int)(System::window->getSize().y - button->getSize().y)	));*/
		textbox.setValue(L"Happy birthday, Vlad!!!");
	}
};

class TextboxEvent : public ui::ITextbox {
public:
	virtual void onClick(ui::Textbox *textbox) {
	}

	virtual void onChange(ui::Textbox *textbox) {
	}
};

bool init() {
	sf::Font *fontUI = new sf::Font();
	if (!fontUI->loadFromFile("c:\\Windows\\Fonts\\tahoma.ttf")) {
		return false;
	}
	//ui::Res::add("gui", fontUI);
	ui::UI::setDefaultFont(fontUI);
	
	ButtonEvent *buttonEvent = new ButtonEvent();
	TextboxEvent *textboxEvent = new TextboxEvent();
	
	button.init();
	button.setCaption(L"Click me!");
	button.setTextSize(20);
	button.setPosition(sf::Vector2f(15, 30));
	button.setEvent(buttonEvent);

	textbox.init();
	textbox.setTextSize(25);
	textbox.setPosition(sf::Vector2f(15, 80));
	textbox.setSize(sf::Vector2f(285, 50));
	textbox.setEvent(textboxEvent);

	return true;
}

void update() {
	button.update();
	textbox.update();
}

void resize(sf::Vector2u size) {
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	sf::RenderWindow window(sf::VideoMode(APP_WIDTH, APP_HEIGHT), APP_NAME);
	window.setFramerateLimit(60);
	System::window = &window;
	sf::View view(window.getDefaultView());
	Input::init();

	if (!init())
		return -1;

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
			window.draw(textbox);
		}
		window.display();

		Input::flush();
	}

	return 0;
}