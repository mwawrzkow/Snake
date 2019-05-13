/*
 * Tile.h
 *
 *  Created on: May 11, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_STATES_GAME_TILE_H_
#define SRC_STATES_GAME_TILE_H_
#include "../../WindowStates/LoadSprite/ObjectInterface.h"
namespace Unit {

class Tile : public Graphic::ObjectInterface{
	int x,y;
public:
	Tile(const Graphic::ObjectInterface&);
	Tile(const Graphic::ObjectInterface&,int,int);

	virtual ~Tile();
	void update();
	void setPosition(float,float);
};

} /* namespace GraphicEvents */

#endif /* SRC_STATES_GAME_TILE_H_ */
