/*
 * Game.cpp
 *
 *  Created on: May 8, 2019
 *      Author: mwawrzkow
 */

#include "Game.h"

namespace SnakeState {

Game::Game(std::string FileList, std::shared_ptr<Texture::Cache> TextureCache,
		bool* sendRequest) :
		State::State(FileList, TextureCache, sendRequest) {
	// TODO Auto-generated constructor stub
	StateAdd("SNAKEHEAD");
	StateAdd("SNAKEBODY");
	StateAdd("BLOCK");
	StateAdd("EATABLE");
	StateAdd("BOARD");
	GameControler = new Controller::GameController("Janusz.");
	State::start();

}
void Game::CreateUnits() {
	int width = GameControler->getView()->getBoardWidth();
	int height = GameControler->getView()->getBoardHeight();
	for (int i = 0; i < Render.getQueue().size(); i++) {
		if (Render.getQueue().at(i)->getSpriteOptions().getName()
				== availibeNames[0]) {
			int x =
					GameControler->getView()->getSnake(Board::playerNumber::one)->requestHeadPosition().x;
			int y =
					GameControler->getView()->getSnake(Board::playerNumber::one)->requestHeadPosition().y;
			snakeface = new Unit::Tile(*Render.getQueue().at(i), x, y);
			snakeface->setPosition(100 * x, 100 * y);
		} else if (Render.getQueue().at(i)->getSpriteOptions().getName()
				== availibeNames[1]) {
			int size = GameControler->getView()->getSnake(
					Board::playerNumber::one)->getParts().size();
			for (int e = 1; e < size; e++) {
				int x = GameControler->getView()->getSnake(
						Board::playerNumber::one)->getParts().at(e).x;
				int y = GameControler->getView()->getSnake(
						Board::playerNumber::one)->getParts().at(e).y;
				Unit::Tile *tmp;
				tmp = new Unit::Tile(*Render.getQueue().at(i), x, y);
				snakebody.push_back(tmp);
				tmp->setPosition(100 * x, 100 * y);
			}
		} else if (Render.getQueue().at(i)->getSpriteOptions().getName()
				== availibeNames[2]) {
			for (int x = 0; x <= width; x++)
				for (int y = 0; y <= height; y++)
					if (GameControler->getView()->getBlockType(x, y)
							== Board::blockType::brick) {
						Unit::Tile * tmp;
						tmp = new Unit::Tile(*Render.getQueue().at(i), x, y);
						tmp->setPosition(100 * x, 100 * y);
						//brick.push_back(tmp);
					}

		} else if (Render.getQueue().at(i)->getSpriteOptions().getName()
				== availibeNames[3]) {
			for (int x = 0; x <= width; x++)
				for (int y = 0; y <= height; y++)
					if (GameControler->getView()->getBlockType(x, y)
							== Board::blockType::eatable) {
						eatable = new Unit::Tile(*Render.getQueue().at(i), x,
								y);
						eatable->setPosition(100, 100);
					}

		} else if (Render.getQueue().at(i)->getSpriteOptions().getName()
				== availibeNames[4]) {
			int width = GameControler->getView()->getBoardWidth();
			int height = GameControler->getView()->getBoardHeight();
			for (int x = 0; x <= width; x++)
				for (int y = 0; y <= height; y++)
					if (GameControler->getView()->getBlockType(x, y)
							== Board::blockType::board) {
						Unit::Tile *tmp;
						tmp = new Unit::Tile(*Render.getQueue().at(i), x, y);
						tmp->setPosition(100 * x, 100 * y);
						board.push_back(tmp);
					}

		}
	}
	Units.insert(Units.end(), brick.begin(), brick.end());
	Units.insert(Units.end(), board.begin(), board.end());
	Units.push_back(snakeface);
	Units.push_back(eatable);
	Units.insert(Units.end(), snakebody.begin(), snakebody.end());

}
void Game::setUnits() {


}
Game::~Game() {
	// TODO Auto-generated destructor stub
}
void Game::update() {
	sf::Time jump = sf::seconds(0.25);
	if (jump <= clock.getElapsedTime()) {
		GameControler->update();
		CreateUnits();
		clock.restart();
	}
}
void Game::update(Unit::move move) {
	GameControler->askPlayerOne(move);
}

} /* namespace Window */
;
