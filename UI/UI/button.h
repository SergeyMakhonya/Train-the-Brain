/*	Copyright © 2014 Sergey Makhonya, Vlad Kudelko
 *	licensed under the terms of the GNU General Public License (GPL) version 3
 */

#ifndef _UI_BUTTON
#define _UI_BUTTON

#include <sfml\Graphics.hpp>

#include "ui.h"
#include "input.h"

namespace ui {
	class Button;
	
	class IButton {
	public:
		virtual ~IButton() {}
		virtual void onClick(ui::Button *button) = 0;
	};

	class Button :	public UI,
					public sf::Drawable,
					public sf::Transformable {
	private:
		std::wstring caption;
		IButton *e;
		sf::Text text;
	public:
		virtual void init() {
			rect.setSize(sf::Vector2f(150, 35));
			_isHover = false;
			_isDown = false;
			_isHoverHit = false;

			text.setFont(*ui::UI::font);
			text.setColor(sf::Color::Black);
		}

		virtual void update() {
			sf::Vector2i mousePos = Input::getMousePos();
			sf::Vector2f uiPos = getPosition();

			bool stateChange = false;

			if (rect.getGlobalBounds().contains(mousePos.x - uiPos.x, mousePos.y - uiPos.y)) {
				if (Input::isMouseDown(sf::Mouse::Left)) {
					stateChange = !_isDown;
					_isDown = true;

					if (Input::isMouseHit(sf::Mouse::Left))
						_isHoverHit = true;
				}
				else {
					stateChange = !_isHover || _isDown;

					if (_isDown && _isHoverHit)
						e->onClick(this);

					_isHover = true;
					_isDown = false;
					_isHoverHit = false;
				}
			}
			else {
				if (!Input::isMouseDown(sf::Mouse::Left)) {
					stateChange = _isHover;
					_isHover = false;
					_isDown = false;
					_isHoverHit = false;
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

		void calcTextPosition() {
			sf::Vector2f size = rect.getSize();
			sf::FloatRect txtRect = text.getGlobalBounds();
			text.setPosition(sf::Vector2f((int)(size.x / 2 - txtRect.width / 2), (int)(size.y / 2 - txtRect.height)));
		}

		void setCaption(std::wstring value) {
			caption = value;
			text.setString(value);

			calcTextPosition();
		}

		void setTextSize(unsigned int size) {
			text.setCharacterSize(size);

			calcTextPosition();
		}

		void setEvent(IButton *e) {
			this->e = e;
		}

		sf::Vector2f getSize() {
			return rect.getSize();
		}

	private:
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
			states.transform *= getTransform();
			target.draw(rect, states);
			target.draw(text, states);
		}
	};
}

#endif