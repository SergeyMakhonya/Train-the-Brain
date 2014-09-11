#ifndef _GLOBAL
#define _GLOBAL

#include <Windows.h>
#include <SFML\Graphics.hpp>

#define APP_NAME L"Train the Brain"
#define APP_ERROR_TITLE L"Train the Brain: Error"
#define APP_WIDTH 1024
#define APP_HEIGHT 600

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