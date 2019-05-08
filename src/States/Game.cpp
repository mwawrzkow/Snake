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
	StateAdd("ENDOFSNAKEBODY");
	StateAdd("BLOCK");
	StateAdd("BOARD");
	GameControler = new Controller::GameController("Janusz.");

}
void Game::CreateUnits(){

}
void Game::setUnits(){

}
Game::~Game() {
	// TODO Auto-generated destructor stub
}

} /* namespace Window */
