/*
 * SnakeBoard.h
 *
 *  Created on: 7 maj 2019
 *      Author: marcin
 */

#ifndef SRC_GAMELOGIC_SNAKE_GRID_SNAKEBOARD_H_
#define SRC_GAMELOGIC_SNAKE_GRID_SNAKEBOARD_H_
#include "Field/Field.h"
#include "Snake.h"
#include "../Player.h"
namespace Board {
enum gamestate {
	win, loss, running
};

class SnakeBoard {
	Unit::Snake *Player1;
	Unit::Snake *Player2;
	Grid::Field board[100][100];
	const int width, height;
	std::vector<Unit::UnitPosition> lastKnownPosition;

protected:
	gamestate state = running;
	void clearBoard();
	void generateBoard();
	void putEatable();
	void putSnake();
	bool isOnEtable();
	bool doesSnakeHitBoard();
public:
	SnakeBoard(int, int, Unit::Snake*);
	SnakeBoard(int, int, Unit::Snake*, Unit::Snake*);
	void debugDisplay();
	gamestate getGameState();
	void update();
public:
	const bool isRightField(int,int)const;
	const bool isEmpty(int,int) const;
	const bool isBrick(int,int) const;
	const bool isEatable(int,int) const;
	const int getWidth()const;
	const int getHeight()const;
};

} /* namespace Terrain */

#endif /* SRC_GAMELOGIC_SNAKE_GRID_SNAKEBOARD_H_ */
