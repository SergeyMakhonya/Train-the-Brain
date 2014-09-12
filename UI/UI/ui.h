/*	Copyright © 2014 Sergey Makhonya, Vlad Kudelko
 *	licensed under the terms of the GNU General Public License (GPL) version 3
 */

#ifndef _UI
#define _UI

#include <sfml\Graphics.hpp>

namespace ui {
	class UI {
	protected:
		sf::RectangleShape rect;
		bool _isHover, _isDown, _isHoverHit;
	public:
		virtual void init() = 0;
		virtual void update() = 0;
	};
}

#endif