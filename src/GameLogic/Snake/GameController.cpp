/*
 * GameController.cpp
 *
 *  Created on: 8 maj 2019
 *      Author: marcin
 */

#include "GameController.h"
#include <iostream>
namespace Controller {

GameController::GameController() {
	std::cerr << "CREATED EMPTY GAMECONTROLER!!" << std::endl
			<< "CREATING NULLPTR";
	playerTwo = nullptr;
	playerOne = nullptr;
	board = nullptr;
	view = nullptr;
}
GameController::GameController(std::string name) {
	playerTwo = nullptr;
	playerOne = new Unit::Player(name);
	board = new Board::SnakeBoard(15, 15, playerOne);
	view = new Board::BoardView(board, playerTwo, playerOne);

}
GameController::GameController(std::string playerone, std::string playertwo) {
	playerOne = new Unit::Player(playerone);
	playerTwo = new Unit::Player(playertwo);
	board = new Board::SnakeBoard(30, 30, playerOne, playerTwo);
	view = new Board::BoardView(board, playerTwo, playerOne);
}
void GameController::debugStart() {
	while (board->getGameState() == Board::gamestate::running) {
		if (playerTwo != nullptr) {
			int move;
			std::cin >> move;
			playerTwo->requestMove(static_cast<Unit::move>(move));
		}
		if (playerOne != nullptr) {
			int move;
			std::cin >> move;
			playerOne->requestMove(static_cast<Unit::move>(move));
		}
		board->update();
	}
}
} /* namespace Unit */
