/*
 * StateController.h
 *
 *  Created on: Apr 25, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_WINDOWSTATES_STATE_H_
#define SRC_WINDOWSTATES_STATE_H_

#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <vector>
#include "../GameLogic/Snake/GameController.h"
#include "LoadSprite/ObjectInterface.h"
#include "WindowStates.h"
#include "LoadSprite/RenderClass.h"
namespace Controller {

class State {
protected:
	WindowState::RenderClass Render;
	GameState::State askState;
	std::vector<std::string>availibeNames;
	std::vector<Graphic::ObjectInterface*>Units;
	virtual void CreateUnits() = 0;
	bool *sendRequest;
public:
	State(std::string,std::shared_ptr<Texture::Cache>TextureCache, bool*);
	void StateAdd(std::string);
	virtual ~State();
	virtual void LoadFiles();
	virtual void update();
	virtual void start();
	virtual void setUnits() = 0;
	virtual std::vector<Graphic::ObjectInterface*>*getUnits();
	virtual void resetStates();
	virtual GameState::State AskedState();
};

} /* namespace Controller */

#endif /* SRC_WINDOWSTATES_STATE_H_ */
