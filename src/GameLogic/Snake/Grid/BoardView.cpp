/*
 * BoardView.cpp
 *
 *  Created on: May 8, 2019
 *      Author: mwawrzkow
 */

#include "BoardView.h"

namespace Board {

BoardView::BoardView(SnakeBoard* board,Unit::Snake* playerone,Unit::Snake* playertwo) :
		board(board),SnakeOne(playerone),SnakeTwo(playertwo) {
	// TODO Auto-generated constructor stub

}
blockType BoardView::getBlockType(int x, int y) {
	if (board->isBrick(x, y))
		return blockType::brick;
	if (board->isEmpty(x, y))
		return blockType::board;
	if (board->isEatable(x, y))
		return blockType::eatable;
	return blockType::ERROR;
}
BoardView::~BoardView() {
	// TODO Auto-generated destructor stub
}
Unit::Snake* BoardView::getSnake(playerNumber choice){
	switch(choice){
	case one:
		return SnakeOne;
		break;
	case two:
		return SnakeTwo;
		break;
	default:
		return nullptr;
	}
}
const int BoardView::getBoardHeight() const{
	return board->getHeight();
}
const int BoardView::getBoardWidth()const {
	return board->getWidth();
}
} /* namespace Board */
