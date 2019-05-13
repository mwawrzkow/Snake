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
#include "Grid/BoardView.h"
namespace Controller{

class GameController {
	Board::SnakeBoard *board;
	Unit::Snake *playerOne;
	Unit::Snake *playerTwo;
	Board::BoardView *view;

public:
	GameController(std::string,std::string);
	GameController(std::string);
	GameController();
	void debugStart();
	void update();
	Board::BoardView* getView();
	void askPlayerOne(Unit::move);
};

} /* namespace Unit */

#endif /* SRC_GAMELOGIC_SNAKE_GAMECONTROLLER_H_ */
