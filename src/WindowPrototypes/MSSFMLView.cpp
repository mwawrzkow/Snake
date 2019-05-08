/*
 * MSSFMLView.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: marcin
 */

#include "MSSFMLView.h"
#include "../WindowStates/LoadSprite/texturebackend/Cache.h"
namespace Graphic {
SFML_Controler::SFML_Controler(Graphic::Render &window, IO::FileManager &settings,
		std::string gamedir) :
		Cache(new Texture::Cache), TextureCache(Cache), window(window), gamedir(
				gamedir), settings(settings), WindowState(
				GameState::State::MainMenu),Event(window.getMutex()) {
	createGameStates();
	Event.setWindow(window.getWindow());
	start();
}
void SFML_Controler::createGameStates() {

}

void SFML_Controler::start() {
	stateHasChanged = true;
	sf::Clock timer;
	while (window.window.isOpen()) {
		if (stateHasChanged)
			stateOfView();
		if (!doesRenderThreadWork) {
			try {
				Display.start(window);
				doesRenderThreadWork = true;
			} catch (Poco::Exception &e) {
				std::cout << e.message() << std::endl;
			}
		}
		//window.runThreadSafe();
		states[WindowState]->update();
		Event.EventChecker();
		if (isAskingForChange)
		{
			WindowState = states[WindowState]->AskedState();
			stateHasChanged = true;
			isAskingForChange = false;
		}
	}

}

void SFML_Controler::stateOfView() {

}
SFML_Controler::~SFML_Controler() {
}
}
