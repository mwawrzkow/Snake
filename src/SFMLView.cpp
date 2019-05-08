/*
 * SFMLView.cpp
 *
 *  Created on: 8 maj 2019
 *      Author: marcin
 */

#include "SFMLView.h"

namespace Window {

SFML_View::SFML_View(SnakeRender& toRender, IO::FileManager& fileio,
		std::string location) :
		Graphic::SFML_Controler(toRender, fileio, location) {
	// TODO Auto-generated constructor stub

}
void SFML_View::createGameStates() {
	SnakeState::Game* Game = new SnakeState::Game(
			gamedir
					+ settings.LoadFileInformation(
							IO::Information::GAME_FILE_LIST).value,
			TextureCache, &isAskingForChange);

}

} /* namespace Unit */
