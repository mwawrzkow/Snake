/*
 * Snake.cpp
 *
 *  Created on: 7 maj 2019
 *      Author: marcin
 */

#include "Snake.h"

namespace Unit {

Snake::Snake() :
		lenght(2) {
}
void Snake::setPosition(int x, int y) {
	for (int lenght = 0; lenght < 3; lenght++) {
		UnitPosition tmp;
		tmp.y = x;
		tmp.x = y - lenght;
		parts.push_back(tmp);
	}
}
const std::vector<UnitPosition> Snake::getParts() const{
	return parts;
}
void Snake::requestMove(move request) {
	if(request != lastRequestedMove)
		reqMove = request;
}
const bool Snake::isAlive()const{
	return alive;
}
void Snake::expandLenght() {
	parts.push_back(parts.at(lenght-1));
	lenght++;
	waitWithLastPart = true;
}
void Snake::update(){
	int tmpx, tmpy;
	for(int e = 0; e<lenght;e++)
	{
		if(e==0)
		{
			tmpx = parts.at(0).x;
			tmpy = parts.at(0).y;
			switch(reqMove)
			{
			case move::up:
				parts.at(0).x++;
				lastRequestedMove = move::down;
				break;
			case move::down:
				parts.at(0).x--;
				lastRequestedMove = move::up;
				break;
			case move::left:
				parts.at(0).y--;
				lastRequestedMove = move::right;
				break;
			case move::right:
				parts.at(0).y++;
				lastRequestedMove = move::left;
				break;
			}
			for(int e = 1; e < lenght; e++)
			{
				if(parts.at(0).x == parts.at(e).x)
					if(parts.at(0).y == parts.at(e).y)
						killSnake();
			}
		}else{
			if(e == lenght -1 && waitWithLastPart){

			}else{
				int etmpx = tmpx;
				int etmpy = tmpy;
				tmpx = parts.at(e).x;
				tmpy = parts.at(e).y;
				parts.at(e).x = etmpx;
				parts.at(e).y = etmpy;
				waitWithLastPart = false;
			}
		}

	}
}
void Snake::killSnake(){
	alive = false;
}
const UnitPosition Snake::requestHeadPosition()const{
	return parts.at(0);
}
Snake::~Snake(){}
std::string Snake::getName(){
	return name;
}
const int Snake::getLenght()const{
	return lenght ;
}
} /* namespace Terrain */
