/*
 * SnakeEventHolder.cpp
 *
 *  Created on: May 11, 2019
 *      Author: mwawrzkow
 */

#include "SnakeEventHolder.h"

namespace GraphicEvents {

SnakeEventHolder::SnakeEventHolder(Poco::Mutex *renderMutex) :
		EventHandler(renderMutex) {
	// TODO Auto-generated constructor stub

}

SnakeEventHolder::~SnakeEventHolder() {
	// TODO Auto-generated destructor stub
}
void SnakeEventHolder::EventChecker() {
	renderMutex->lock();
	Objects->update();
	while (window->pollEvent(WindowEvent)) {
		if (WindowEvent.type == sf::Event::KeyPressed) {
			KeyPressed();
		}else if(WindowEvent.type == sf::Event::Closed){
			window->close();
		}
	}
	renderMutex->unlock();

}
void SnakeEventHolder::KeyPressed() {
	if (WindowEvent.key.code == sf::Keyboard::D) {
		Objects->update(Unit::move::up);
	} else if (WindowEvent.key.code == sf::Keyboard::A) {
		Objects->update(Unit::move::down);
	} else if (WindowEvent.key.code == sf::Keyboard::W) {
		Objects->update(Unit::move::left);
	} else if (WindowEvent.key.code == sf::Keyboard::S) {
		Objects->update(Unit::move::right);
	}
}

} /* namespace GraphicEvents */
