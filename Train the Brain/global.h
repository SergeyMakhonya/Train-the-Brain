#ifndef _GLOBAL
#define _GLOBAL

#include <Windows.h>
#include <SFML\Graphics.hpp>
#include <string>

#define APP_NAME L"Train the Brain"
#define APP_ERROR_TITLE L"Train the Brain: Error"

class System {
public:
	static sf::RenderWindow* window;

	static void error(std::wstring message) {
		MessageBox(window->getSystemHandle(), message.c_str(), APP_ERROR_TITLE, 0);
	}

	static void exit() {
		window->close();
	}
};

#endif