/*
 * GameController.h
 *
 *  Created on: 8 maj 2019
 *      Author: marcin
 */

#ifndef SRC_GAMELOGIC_SNAKE_GAMECONTROLLER_H_
#define SRC_GAMELOGIC_SNAKE_GAMECONTROLLER_H_
#include "Player.h"
#include "Grid/SnakeBoard.h"
namespace Controller{

class GameController {
	Board::SnakeBoard *board;
	Unit::Snake *playerOne;
	Unit::Snake *playerTwo;

public:
	GameController(std::string,std::string);
	GameController(std::string);
	GameController();
	void debugStart();
	Unit::Snake* getPlayerOne();
	Unit::Snake* getPlayerTwo();
};

} /* namespace Unit */

#endif /* SRC_GAMELOGIC_SNAKE_GAMECONTROLLER_H_ */
