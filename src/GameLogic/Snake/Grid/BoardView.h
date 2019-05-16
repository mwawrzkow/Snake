/*
 * BoardView.h
 *
 *  Created on: May 8, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_GAMELOGIC_SNAKE_GRID_BOARDVIEW_H_
#define SRC_GAMELOGIC_SNAKE_GRID_BOARDVIEW_H_
#include "SnakeBoard.h"
namespace Board {
enum blockType {
	ERROR, brick, board, eatable,
};
enum playerNumber {
	one, two
};
class BoardView {
	const SnakeBoard *board;
	Unit::Snake *SnakeOne;
	Unit::Snake *SnakeTwo;
public:
	BoardView(SnakeBoard*, Unit::Snake*, Unit::Snake*);
	blockType getBlockType(int, int);
	virtual ~BoardView();
	Unit::Snake* getSnake(playerNumber) ;
	const int getBoardWidth() const;
	const int getBoardHeight() const;
};

} /* namespace Board */

#endif /* SRC_GAMELOGIC_SNAKE_GRID_BOARDVIEW_H_ */
