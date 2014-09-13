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

	class Button :	public UI {
	private:
		std::wstring caption;
		IButton *e;
		sf::Text text;
	public:
		virtual void init() {
			initUI();

			rect.setSize(sf::Vector2f(150, 35));
			text.setFont(*ui::UI::font);
			text.setColor(sf::Color::Black);
		}

		virtual void update() {
			updateUI();
		}

		virtual void onMouseDown() {
			if (_isHover)
				rect.setFillColor(sf::Color::Red);
		}

		virtual void onMouseUp() {
			if (_isHover)
				rect.setFillColor(sf::Color::Yellow);
			else
				rect.setFillColor(sf::Color::White);
		}

		virtual void onClick() {
			e->onClick(this);
		}

		void calcTextPosition() {
			sf::Vector2f size = rect.getSize();
			sf::FloatRect txtRect = text.getGlobalBounds();
			text.setPosition(sf::Vector2f((int)(size.x / 2 - txtRect.width / 2), (int)(size.y / 2 - 13)));
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