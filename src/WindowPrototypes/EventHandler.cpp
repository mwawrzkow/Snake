/*
 * EventHandler.cpp
 *
 *  Created on: Apr 25, 2019
 *      Author: mwawrzkow
 */

#include "EventHandler.h"
#include <iostream>
namespace SFML_Handlers {

EventHandler::EventHandler(Poco::Mutex *renderMutex) :
		window(new sf::RenderWindow),Objects(),renderMutex(renderMutex){
	// TODO Auto-generated constructor stub

}
void EventHandler::setWindow(sf::RenderWindow &window) {
	this->window = &window;
}
void EventHandler::closeGame(){
	window->close();
}
void EventHandler::EventChecker() {
	renderMutex->lock();
	while (window->pollEvent(WindowEvent)) {
		// "close requested" event: we close the window
		if (WindowEvent.type == sf::Event::Closed)
			window->close();
		if (WindowEvent.type == sf::Event::MouseButtonPressed)
			mousePress();
	}
	renderMutex->unlock();
}
void EventHandler::mousePress() {
	float x = WindowEvent.mouseButton.x;
	float y = WindowEvent.mouseButton.y;
	for (Graphic::ObjectInterface *tmp : *Objects->getUnits()) {
		float startx = tmp->returnSprite()->getPosition().x;
		float starty = tmp->returnSprite()->getPosition().y;
		float height = tmp->getSpriteOptions().getsHeight() + starty;
		float width = tmp->getSpriteOptions().getsWidth() + startx;
	if(x <= width && x >= startx && y<= height && y>=starty)
	{
		switch (WindowEvent.mouseButton.button){
		case sf::Mouse::Right:
			if(tmp->ClickEvent()->isRClicable)
			{
				tmp->updateState("rclick");
			}
			break;
		case sf::Mouse::Left:
			if(tmp->ClickEvent()->isClicable)
			{
				tmp->updateState("click");
			}
			break;
		}
	}

}
}
void EventHandler::setObjects(Controller::State *tmp) {
Objects = tmp;

}
EventHandler::~EventHandler() {
// TODO Auto-generated destructor stub
}
} /* namespace SFML_Handlers */
