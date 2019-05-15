/*
 * Render.h
 *
 *  Created on: May 8, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_RENDER_H_S
#define SRC_RENDER_H_S
#include "WindowPrototypes/Render.h"
namespace Window {

class SnakeRender :public Graphic::Render{
	sf::View view;
public:
	SnakeRender(sf::RenderWindow&);
	virtual ~SnakeRender();
};

} /* namespace Window */

#endif /* SRC_RENDER_H_ */
