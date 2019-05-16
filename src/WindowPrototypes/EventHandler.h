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
#include "Poco/Runnable.h"

namespace SFML_Handlers {

class EventHandler{
protected:
	Poco::Mutex EventMutex;
	sf::Event WindowEvent;
	sf::RenderWindow *window;
	Controller::State *Objects;
public:
	EventHandler();
	void setWindow(sf::RenderWindow&);
	virtual void EventChecker();
	void setObjects(Controller::State&);
	virtual ~EventHandler();
	void closeGame();
private:
	void mousePress();
};

} /* namespace SFML_Handlers */

#endif /* EVENTHANDLER_H_ */
