/*
 * Player.h
 *
 *  Created on: 7 maj 2019
 *      Author: marcin
 */

#ifndef SRC_GAMELOGIC_PLAYER_H_
#define SRC_GAMELOGIC_PLAYER_H_
#include "Grid/Snake.h"
namespace Unit {

class Player : public Snake{
public:

	Player(std::string);
};

} /* namespace Unit */

#endif /* SRC_GAMELOGIC_PLAYER_H_ */
