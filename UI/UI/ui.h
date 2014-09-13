/*	Copyright © 2014 Sergey Makhonya, Vlad Kudelko
 *	licensed under the terms of the GNU General Public License (GPL) version 3
 */

#ifndef _UI
#define _UI

#include <sfml\Graphics.hpp>

#include "input.h"

namespace ui {
	class UI : public sf::Drawable, public sf::Transformable {
	protected:
		sf::RectangleShape rect;
		bool _isHover, _isDown;

		static sf::Font *font;
	public:
		virtual void init() = 0;
		virtual void update() = 0;
	private:
		virtual void onMouseDown() = 0;
		virtual void onMouseUp() = 0;
		virtual void onClick() = 0;
	public:
		static void setDefaultFont(sf::Font *font) {
			UI::font = font;
		}
	protected:
		void initUI() {
			_isHover = false;
			_isDown = false;
		}

		void updateUI() {
			updateStates();
		}
	private:
		void updateStates() {
			sf::Vector2i mousePos = Input::getMousePos();
			sf::Vector2f uiPos = getPosition();

			_isHover = rect.getGlobalBounds().contains(mousePos.x - uiPos.x, mousePos.y - uiPos.y);

			if (_isHover) {
				if (Input::isMouseHit(sf::Mouse::Left)) {
					onMouseDown();
					_isDown = true;
				}
				else if (Input::isMouseRelease(sf::Mouse::Left)) {
					onMouseUp();
					if (_isDown)
						onClick();
					_isDown = false;
				}
			}
			else {
				if (Input::isMouseHit(sf::Mouse::Left))
					onMouseDown();
				else if (Input::isMouseRelease(sf::Mouse::Left))
					onMouseUp();
			}
		}
	};
}

#endif