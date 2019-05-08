/*
 * Game.h
 *
 *  Created on: May 8, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_STATES_GAME_H_
#define SRC_STATES_GAME_H_
#include "../WindowStates/State.h"
#include "../GameLogic/Snake/GameController.h"
namespace SnakeState {

class Game : public Controller::State{
private:
	Controller::GameController *GameControler;
public:
	Game(std::string,std::shared_ptr<Texture::Cache>TextureCache,bool*);
	virtual ~Game();
	virtual void CreateUnits();
	virtual void setUnits();
};

} /* namespace Window */

#endif /* SRC_STATES_GAME_H_ */
