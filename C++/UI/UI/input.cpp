/*	Copyright © 2014 Sergey Makhonya, Vlad Kudelko
 *	licensed under the terms of the GNU General Public License (GPL) version 3
 */

#include "input.h"

bool Input::mouseHit[3];
bool Input::mouseRelease[3];
//bool Input::mouseDown[3];

bool Input::needFlush = false;

int Input::mouseX0 = 0, Input::mouseY0 = 0, Input::mouseSX = 0, Input::mouseSY = 0, Input::mouseSZ = 0;
int Input::mouseHitX[3], Input::mouseHitY[3];

std::vector<sf::Keyboard::Key> Input::keyPressed;
std::vector<sf::Keyboard::Key> Input::keyReleased;