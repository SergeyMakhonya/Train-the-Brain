#ifndef _UI_BUTTON
#define _UI_BUTTON

#include <sfml\Graphics.hpp>

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
		}

		virtual void update() {
			sf::Vector2i mousePos = Input::getMousePos();
			if (rect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				if (!_isHover)
					rect.setFillColor(sf::Color(255, 190, 0));
			}
			else {
				if (_isHover)
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