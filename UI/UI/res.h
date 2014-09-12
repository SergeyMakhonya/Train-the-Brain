/*	Copyright © 2014 Sergey Makhonya, Vlad Kudelko
 *	licensed under the terms of the GNU General Public License (GPL) version 3
 */

#ifndef _RESOURCES
#define _RESOURCES

#include <sfml\Graphics.hpp>
#include <map>

namespace ui {
	class Res {
	private:
		static std::map<std::string, sf::Font*> fonts;
	public:
		static void add(std::string name, sf::Font *font) {
			fonts[name] = font;
		}

		static sf::Font *getFont(std::string name) {
			return fonts[name];
		}
	};
}

#endif