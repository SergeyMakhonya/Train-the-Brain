/*	Copyright © 2014 Sergey Makhonya, Vlad Kudelko
 *	licensed under the terms of the GNU General Public License (GPL) version 3
 */

#ifndef _INPUT
#define _INPUT

#include <SFML\Window.hpp>
#include "global.h"

class Input {
private:
	static bool mouseHit[3];
	static bool mouseRelease[3];
	//static bool mouseDown[3];

	static bool needFlush;

	static int mouseX0, mouseY0, mouseSX, mouseSY, mouseSZ;
	static int mouseHitX[3], mouseHitY[3];

	static std::vector<sf::Keyboard::Key> keyPressed;
	static std::vector<sf::Keyboard::Key> keyReleased;
public:
	static void init() {
		memset(&mouseHitX, 0, sizeof(mouseHitX));
		memset(&mouseHitY, 0, sizeof(mouseHitY));
	}

	static void analyseEvent(sf::Event e) {
		if (e.type == e.MouseButtonPressed) {
			sf::Vector2i mousePos = getMousePos();

			if (e.mouseButton.button == sf::Mouse::Left) { mouseHitX[0] = mousePos.x; mouseHitY[0] = mousePos.y; mouseHit[0] = true; needFlush = true; }
			else if (e.mouseButton.button == sf::Mouse::Right) { mouseHitX[1] = mousePos.x; mouseHitY[1] = mousePos.y; mouseHit[1] = true; needFlush = true; }
			else if (e.mouseButton.button == sf::Mouse::Middle) { mouseHitX[2] = mousePos.x; mouseHitY[2] = mousePos.y; mouseHit[2] = true; needFlush = true; }
		}
		else if (e.type == e.MouseButtonReleased) {
			if (e.mouseButton.button == sf::Mouse::Left) { mouseRelease[0] = true; needFlush = true; }
			else if (e.mouseButton.button == sf::Mouse::Right) { mouseRelease[1] = true; needFlush = true; }
			else if (e.mouseButton.button == sf::Mouse::Middle) { mouseRelease[2] = true; needFlush = true; }
		}
		else if (e.type == e.KeyPressed) {
			keyPressed.push_back(e.key.code);
			needFlush = true;
		}
		else if (e.type == e.KeyReleased) {
			keyReleased.push_back(e.key.code);
			needFlush = true;
		}
		else if (e.type == e.MouseMoved) {
			mouseSX = e.mouseMove.x - mouseX0;
			mouseSY = e.mouseMove.y - mouseY0;

			mouseX0 = e.mouseMove.x;
			mouseY0 = e.mouseMove.y;

			needFlush = true;
		}
		else if (e.type == e.MouseWheelMoved) {
			mouseSZ = e.mouseWheel.delta;
			needFlush = true;
		}
	}

	static void flush() {
		if (!needFlush) return;

		mouseHit[0] = false;
		mouseHit[1] = false;
		mouseHit[2] = false;
		mouseRelease[0] = false;
		mouseRelease[1] = false;
		mouseRelease[2] = false;

		keyPressed.clear();
		keyReleased.clear();

		mouseSX = 0;
		mouseSY = 0;
		mouseSZ = 0;

		needFlush = false;
	}

	static inline bool isKeyDown(sf::Keyboard::Key key) { return sf::Keyboard::isKeyPressed(key); }

	static bool isKeyHit(sf::Keyboard::Key key) {
		for (auto code : keyPressed)
			if (code == key)
				return true;

		return false;
	}

	static bool isKeyRelease(sf::Keyboard::Key key) {
		for (auto code : keyReleased)
			if (code == key)
				return true;

		return false;
	}

	static bool isMouseDown(sf::Mouse::Button button) { return sf::Mouse::isButtonPressed(button); }

	static bool isMouseHit(sf::Mouse::Button button) {
		switch (button)	{
		case sf::Mouse::Left:
			return mouseHit[0];
		case sf::Mouse::Right:
			return mouseHit[1];
		case sf::Mouse::Middle:
			return mouseHit[2];
		case sf::Mouse::XButton1:
			break;
		case sf::Mouse::XButton2:
			break;
		case sf::Mouse::ButtonCount:
			break;
		default:
			break;
		}
	}

	static bool isMouseRelease(sf::Mouse::Button button) {
		switch (button)	{
		case sf::Mouse::Left:
			return mouseRelease[0];
		case sf::Mouse::Right:
			return mouseRelease[1];
		case sf::Mouse::Middle:
			return mouseRelease[2];
		case sf::Mouse::XButton1:
			break;
		case sf::Mouse::XButton2:
			break;
		case sf::Mouse::ButtonCount:
			break;
		default:
			break;
		}
	}

	static sf::Vector2i getMousePos() { return sf::Mouse::getPosition(*System::window); }

	static sf::Vector2i getMouseHitPos(sf::Mouse::Button button) {
		return sf::Vector2i(getMouseHitX(button), getMouseHitY(button));
	}
	static int getMouseHitX(sf::Mouse::Button button) {
		switch (button) {
		case sf::Mouse::Left:
			return mouseHitX[0];
		case sf::Mouse::Right:
			return mouseHitX[1];
		case sf::Mouse::Middle:
			return mouseHitX[2];
		case sf::Mouse::XButton1:
			return false;
		case sf::Mouse::XButton2:
			return false;
		case sf::Mouse::ButtonCount:
			return false;
		default:
			return false;
		}
	}
	static int getMouseHitY(sf::Mouse::Button button) {
		switch (button) {
		case sf::Mouse::Left:
			return mouseHitY[0];
		case sf::Mouse::Right:
			return mouseHitY[1];
		case sf::Mouse::Middle:
			return mouseHitY[2];
		case sf::Mouse::XButton1:
			return false;
		case sf::Mouse::XButton2:
			return false;
		case sf::Mouse::ButtonCount:
			return false;
		default:
			return false;
		}
	}
	static int getMouseSX() { return mouseSX; }
	static int getMouseSY() { return mouseSY; }
	static int getMouseSZ() { return mouseSZ; }
};

#endif