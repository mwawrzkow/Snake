/*
 * Render.cpp
 *
 *  Created on: May 8, 2019
 *      Author: mwawrzkow
 */

#include "SnakeRender.h"

namespace Window {

SnakeRender::SnakeRender(sf::RenderWindow& toRender):Graphic::Render(toRender),view(sf::Vector2f(-800, -400), sf::Vector2f(1280.f, 720.f)) {
	view.setSize(2480.f, 1440.f);
	window.setView(view);

}

SnakeRender::~SnakeRender() {
	// TODO Auto-generated destructor stub
}

} /* namespace Window */
