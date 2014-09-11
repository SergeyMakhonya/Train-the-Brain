/*	Copyright © 2014 Sergey Makhonya, Vlad Kudelko
 *	licensed under the terms of the GNU General Public License (GPL) version 3
 */

#ifndef _UI_BUTTON
#define _UI_BUTTON

#include <sfml\Graphics.hpp>

#include "ui.h"
#include "input.h"

namespace ui {
	class Button :	public UI,
					public sf::Drawable,
					public sf::Transformable {
	private:
		std::wstring caption;
	public:
		virtual void init() {
			rect.setSize(sf::Vector2f(150, 35));
			_isHover = false;
			_isDown = false;
		}

		virtual void update() {
			sf::Vector2i mousePos = Input::getMousePos();
			sf::Vector2f uiPos = getPosition();

			bool stateChange = false;

			if (rect.getGlobalBounds().contains(mousePos.x - uiPos.x, mousePos.y - uiPos.y)) {
				if (Input::isMouseDown(sf::Mouse::Left)) {
					stateChange = !_isDown;
					_isDown = true;
				}
				else {
					stateChange = !_isHover || _isDown;
					_isHover = true;
					_isDown = false;
				}
			}
			else {
				if (!Input::isMouseDown(sf::Mouse::Left)) {
					stateChange = _isHover;
					_isHover = false;
					_isDown = false;
				}
			}

			if (stateChange) {
				if (_isDown)
					rect.setFillColor(sf::Color::Red);
				else if (_isHover)
					rect.setFillColor(sf::Color::Yellow);
				else
					rect.setFillColor(sf::Color::White);
			}
		}

		void setCaption(std::wstring value) {
			caption = value;
		}

	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
			states.transform *= getTransform();
			target.draw(rect, states);
		}
	};
}

#endif