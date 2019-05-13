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
	Event = new GraphicEvents::SnakeEventHolder(toRender.getMutex());
	createGameStates();
	Event->setWindow(window.getWindow());
	start();
	// TODO Auto-generated constructor stub

}
void SFML_View::createGameStates() {
	Game = new SnakeState::Game(
			gamedir
					+ settings.LoadFileInformation(
							IO::Information::GAME_FILE_LIST).value,
			TextureCache, &isAskingForChange);
	states.push_back(Game);
	window.renderQueue(*states.at(WindowState));
	Event->setObjects(states.at(WindowState));

}

} /* namespace Unit */
