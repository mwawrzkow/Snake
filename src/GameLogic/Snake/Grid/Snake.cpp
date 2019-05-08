/*
 * Snake.cpp
 *
 *  Created on: 7 maj 2019
 *      Author: marcin
 */

#include "Snake.h"

namespace Unit {

Snake::Snake() :
		lenght(3) {
}
void Snake::setPosition(int x, int y) {
	for (int lenght = 0; lenght < 3; lenght++) {
		UnitPosition tmp;
		tmp.y = x;
		tmp.x = y - lenght;
		parts.push_back(tmp);
	}
}
std::vector<UnitPosition> Snake::getParts() {
	return parts;
}
void Snake::requestMove(move request) {
	switch (request) {
	case move::up:
		if (reqMove != move::down)
			reqMove = request;
		break;
	case move::left:
		if (reqMove != move::right)
			reqMove = request;
		break;
	case move::down:
		if (reqMove != move::up)
			reqMove = request;
		break;
	case move::right:
		if (reqMove != move::left)
			reqMove = request;
	}
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
				break;
			case move::down:
				parts.at(0).x--;
				break;
			case move::left:
				parts.at(0).y--;
				break;
			case move::right:
				parts.at(0).y++;
				break;
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
UnitPosition Snake::requestHeadPosition(){
	return parts.at(0);
}
Snake::~Snake(){}
std::string Snake::getName(){
	return name;
}
int Snake::getLenght(){
	return lenght;
}
} /* namespace Terrain */
