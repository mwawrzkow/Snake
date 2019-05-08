/*
 * MSSFMLView.h
 *
 *  Created on: Mar 11, 2019
 *      Author: Frontend Class for Minesweeper
 */

#ifndef SRC_MSSFMLVIEW_H_
#define SRC_MSSFMLVIEW_H_

//Including SFML Libraries

#include <memory>
#include <string>

#include "../WindowStates/FileIO/FileManager.h"
#include "../WindowStates/WindowStates.h"
#include "Poco/Thread.h"
#include "Render.h"
#include "EventHandler.h"

namespace Graphic {
class SFML_Controler {
protected:
	Texture::Cache *Cache;
	std::shared_ptr<Texture::Cache> TextureCache;
	/*
	 * Main Game Window
	 */
	IO::FileManager &settings;
	Render &window;
	SFML_Handlers::EventHandler Event;
	Poco::Thread Display;
	//Game Graphic objects
	GameState::State WindowState;
	std::vector<Controller::State*> states;
	bool stateHasChanged = false;
	bool doesRenderThreadWork = false;
	bool isAskingForChange = false;
	/*
	 * Important Const
	 */
	const std::string gamedir;
public:
	SFML_Controler(Graphic::Render &window, IO::FileManager &settings,
			std::string gamedir);
	void start();
	virtual ~SFML_Controler();
protected:
	void stateChangeChecker();
	void createGameStates();
private:
	void stateOfView();
	void event();
	void update();
};
}
#endif /* SRC_MSSFMLVIEW_H_ */
