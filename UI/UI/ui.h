#ifndef _UI
#define _UI

#include <sfml\Graphics.hpp>

namespace ui {
	class UI {
	protected:
		sf::RectangleShape rect;
		bool _isHover;
	public:
		virtual void init() = 0;
		virtual void update() = 0;
	};
}

#endif