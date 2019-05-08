/*
 * EventHandler.h
 *
 *  Created on: Apr 25, 2019
 *      Author: mwawrzkow
 */

#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_
#include "Poco/Mutex.h"
#include "SFML/Graphics.hpp"
#include "../WindowStates/LoadSprite/ObjectInterface.h"
#include "../WindowStates/State.h"
namespace SFML_Handlers {

class EventHandler {
	sf::Event WindowEvent;
	sf::RenderWindow *window;
	Controller::State *Objects;
	Poco::Mutex *renderMutex;
public:
	EventHandler(Poco::Mutex *renderMutex);
	void setWindow(sf::RenderWindow&);
	void EventChecker();
	void setObjects(Controller::State*);
	~EventHandler();
	void closeGame();
private:
	void mousePress();
};

} /* namespace SFML_Handlers */

#endif /* EVENTHANDLER_H_ */
