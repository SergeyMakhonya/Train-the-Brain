/*	Copyright © 2014 Sergey Makhonya, Vlad Kudelko
 *	licensed under the terms of the GNU General Public License (GPL) version 3
 */

#ifndef _UI_TEXTBOX
#define _UI_TEXTBOX

#include <sfml\Graphics.hpp>

#include "ui.h"
#include "input.h"

namespace ui {
	class Textbox;
	
	class ITextbox {
	public:
		virtual ~ITextbox() {}
		virtual void onClick(ui::Textbox *textbox) = 0;
		virtual void onChange(ui::Textbox *textbox) = 0;
	};

	class Textbox :	public UI {
	private:
		std::wstring value;
		ITextbox *e;
		sf::Text text;
	public:
		virtual void init() {
			initUI();

			rect.setSize(sf::Vector2f(150, 30));
			text.setFont(*ui::UI::font);
			text.setColor(sf::Color::Black);
			text.setPosition(8, 8);
		}

		virtual void update() {
			updateUI();
		}

		virtual void onMouseDown() {
		}

		virtual void onMouseUp() {
		}

		virtual void onClick() {
			e->onClick(this);
		}

		virtual void onHoverChange() {
		}

		void setValue(std::wstring value) {
			this->value = value;
			text.setString(value);
		}

		void setTextSize(unsigned int size) {
			text.setCharacterSize(size);
		}

		void setEvent(ITextbox *e) {
			this->e = e;
		}

		void setSize(sf::Vector2f value) {
			rect.setSize(value);
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