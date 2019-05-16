/*
 * Render.h
 *
 *  Created on: Apr 24, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_RENDER_H_
#define SRC_RENDER_H_
#include "Poco/Mutex.h"
#include "Poco/ScopedLock.h"
#include <SFML/Graphics.hpp>
#include "Poco/Runnable.h"
#include "../WindowStates/State.h"
#include "EventHandler.h"
namespace Graphic {

class Render : Poco::Runnable{
	Poco::Mutex mutex;
	std::vector<ObjectInterface*>*toRender;
	SFML_Handlers::EventHandler *event;
	sf::Clock tmp;
protected:
	sf::RenderWindow &window;
public:
	Render(sf::RenderWindow&);
	void renderQueue(Controller::State&);
	void run();
	void runThreadSafe();
	void setEvent(SFML_Handlers::EventHandler &);
	~Render();
	sf::RenderWindow &getWindow();
	Poco::Mutex* getMutex();
	friend class SFML_Controler;
};

} /* namespace Objects */

#endif /* SRC_RENDER_H_ */
