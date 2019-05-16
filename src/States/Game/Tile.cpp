/*
 * Tile.cpp
 *
 *  Created on: May 11, 2019
 *      Author: mwawrzkow
 */

#include "Tile.h"

namespace Unit {

Tile::Tile(const Graphic::ObjectInterface& settings) :
		ObjectInterface(settings) {
	createSprite();
	// TODO Auto-generated constructor stub

}
Tile::Tile(const Graphic::ObjectInterface& settings, int x, int y) :
		ObjectInterface(settings), x(x), y(y) {
	createSprite();

}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}
void Tile::update() {

}
void Tile::setPosition(float x, float y) {
	Sprite.setOrigin(sf::Vector2f(x,y));
}
} /* namespace GraphicEvents */
