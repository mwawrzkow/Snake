/*
 * SnakeBoard.cpp
 *
 *  Created on: 7 maj 2019
 *      Author: marcin
 */

#include "SnakeBoard.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

namespace Board {
gamestate SnakeBoard::getGameState(){
	return state;
}

SnakeBoard::SnakeBoard(int x, int y, Unit::Snake* Player) :
		width(x), height(y),Player1(Player) {
	std::cout << "Welcome " << Player1->getName() << "!" << std::endl;
	generateBoard();
	putEatable();
	putSnake();
}
SnakeBoard::SnakeBoard(int x , int y, Unit::Snake* Player1, Unit::Snake* Player2):width(x),height(y),Player1(Player1),Player2(Player2){
	std::cout << "Welcome " << Player1->getName() << "!" << std::endl;
	std::cout << "Welcome " << Player2->getName() << "!" << std::endl;
		generateBoard();
		putEatable();
		putSnake();
}
bool SnakeBoard::isOnEtable(){
	int x =Player1->requestHeadPosition().x;
	int y = Player1->requestHeadPosition().y;
	if(board[x][y].eatable)
	{
		board[x][y].eatable = false;
		putEatable();
		return true;
	}
	return false;
}
void SnakeBoard::generateBoard() {
	for (int x = 1; x <= width; x++)
		for (int y = 1; y <= height; y++) {
			board[x][y].isBlock = false;
		}
	board[5][6].eatable = true;
}
void SnakeBoard::debugDisplay() {
	for (int x = 0; x <= width + 1; x++) {
		for (int y = 0; y <= height + 1; y++) {
			std::cout << "[";
			if (board[x][y].isBlock)
				std::cout << "B";
			else if (board[x][y].eatable)
				std::cout << "E";
			else if (board[x][y].isplayer)
				if(x == Player1->requestHeadPosition().x && y == Player1->requestHeadPosition().y)
				{
					std::cout <<"G";}

				else
				std::cout << "P";
			else
				std::cout << ".";
			std::cout << "]";
		}
		std::cout << std::endl;
	}
}
bool SnakeBoard::doesSnakeHitBoard(){
	int x = Player1->requestHeadPosition().x;
	int y = Player1->requestHeadPosition().y;
	if(board[x][y].isBlock)
	return true;
	return false;
}
void SnakeBoard::clearBoard(){
	for(Unit::UnitPosition &e: lastKnownPosition)
		board[e.x][e.y].isplayer = false;
		std::vector<Unit::UnitPosition> tmp = Player1->getParts();
		for (Unit::UnitPosition &e : tmp) {
			board[e.x][e.y].isplayer = true;
		}
}
void SnakeBoard::update() {
	if(isOnEtable())
	{
		Player1->expandLenght();
	}

	clearBoard();
	if(doesSnakeHitBoard())
		state = loss;
	debugDisplay();
	lastKnownPosition = Player1->getParts();
	if(Player1->isAlive())
	Player1->update();

}
void SnakeBoard::putEatable() {
	srand(time(NULL));
	int rightx, righty;
	bool rightField = false;
	do {
		int x = rand() % width + 1;
		int y = rand() % height + 1;
		if (!board[x][y].isBlock && !board[x][y].isplayer) {
			rightField = true;
			rightx = x;
			righty = y;
		}
	} while (!rightField);

	board[rightx][righty].eatable = true;
}
void SnakeBoard::putSnake() {
	Player1->setPosition(5, 5);

}
} /* namespace Terrain */
