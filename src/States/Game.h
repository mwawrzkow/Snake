/*
 * Game.h
 *
 *  Created on: May 8, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_STATES_GAME_H_
#define SRC_STATES_GAME_H_
#include "../WindowStates/State.h"
namespace Window {

class Game : public Controller::State{
public:
	Game();
	virtual ~Game();
};

} /* namespace Window */

#endif /* SRC_STATES_GAME_H_ */
