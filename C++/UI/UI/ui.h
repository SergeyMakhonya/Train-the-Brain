/*	Copyright © 2014 Sergey Makhonya, Vlad Kudelko
 *	licensed under the terms of the GNU General Public License (GPL) version 3
 */

#ifndef _UI
#define _UI

#include <sfml\Graphics.hpp>
#include <vector>

#include "input.h"

namespace ui {
	class UI : public sf::Drawable, public sf::Transformable {
	protected:
		sf::RectangleShape rect;
		bool _isHover, _isDown;

		static sf::Font *font;
	private:
		static std::vector<UI*> manager_elements;
	public:
		virtual void init() = 0;
	private:
		virtual void update() = 0;
	private:
		virtual void onMouseDown() = 0;
		virtual void onMouseUp() = 0;
		virtual void onClick() = 0;
		virtual void onHoverChange() = 0;
	public:
		static void setDefaultFont(sf::Font *font) {
			UI::font = font;
		}
	protected:
		void initUI() {
			_isHover = false;
			_isDown = false;
			manager_add(this);
		}

		void updateUI() {
			updateStates();
		}
	private:
		void updateStates() {
			sf::Vector2i mousePos = Input::getMousePos();
			sf::Vector2f uiPos = getPosition();

			bool prevHover = _isHover;
			_isHover = rect.getGlobalBounds().contains(mousePos.x - uiPos.x, mousePos.y - uiPos.y);
			if (prevHover != _isHover)
				onHoverChange();

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
				else if (Input::isMouseRelease(sf::Mouse::Left)) {
					onMouseUp();
					_isDown = false;
				}
			}
		}

	public:
		static void manager_update() {
			for (auto ui : manager_elements)
				ui->update();
		}

		static void manager_draw(sf::RenderWindow *win) {
			for (auto ui : manager_elements)
				win->draw(*ui);
		}
	private:
		static void manager_add(UI *ui) {
			manager_elements.push_back(ui);
		}
	};
}

#endif