/*
 * Snake.h
 *
 *  Created on: 7 maj 2019
 *      Author: marcin
 */

#ifndef SRC_GAMELOGIC_SNAKE_GRID_SNAKE_H_
#define SRC_GAMELOGIC_SNAKE_GRID_SNAKE_H_
#include "vector"
#include "Field/UnitPosition.h"
#include "string"
namespace Unit {
enum move {
	up, left, right, down
};

class Snake {
	bool alive = true;
	std::vector<UnitPosition> parts;
	move reqMove;
	int lenght;
	bool waitWithLastPart = false;
protected:
	std::string name;
public:
	Snake();
	virtual void setPosition(int, int);
	virtual const std::vector<UnitPosition> getParts() const;
	virtual void requestMove(move);
	virtual void expandLenght();
	virtual void update();
	virtual void killSnake();
	virtual const bool isAlive() const;
	virtual const UnitPosition requestHeadPosition() const;
	virtual std::string getName();
	virtual ~Snake();
	virtual const int getLenght() const;
};

} /* namespace Terrain */

#endif /* SRC_GAMELOGIC_SNAKE_GRID_SNAKE_H_ */
