/*
 * ClickEvent.cpp
 *
 *  Created on: 13 kwi 2019
 *      Author: marcin
 */

#include "ClickEvent.h"
#include <SFML/Graphics.hpp>
#include "ObjectInterface.h"

namespace ObjectSettings {
ClickOptions::ClickOptions()
:isClicable(false),isHoverable(false),isRClicable(false)
{
}
/*
 * class ClickEvent {
 bool click;
 bool hold;
 bool rclick;
 public:
 void setClicable();
 void setHoldable();
 void setRClicable();
 ClickEvent();
 bool isClicable(Graphic::Object &obj);
 void ClickEvent(Graphic::Object &obj, sf::Event event);
 protected:
 bool isClicable(Graphic::Object &obj) const ;
 bool isHoldable(Graphic::Object &obj) const ;
 bool isrclick(Graphic::Object &obj) const ;

 };
 */

Click::Click():isclicked(false)
{
}
void Click::ToggleClicable() {
	Options.isClicable = !Options.isClicable;
}

void Click::ToggleHoverable() {
	Options.isHoverable = !Options.isHoverable;
}

void Click::ToggleRClicable() {
	Options.isRClicable = !Options.isRClicable;
}

ClickOptions* Click::ClickEvent(){
	return &Options;
}
bool Click::checkClick(){
	return isclicked;
}
bool Click::checkrClick(){
	return isrclicked;
}
void Click::rclick(){
	isrclicked =true;
}
Click::~Click(){}
/*
 * 	virtual void click();
	virtual void hover();
	virtual void rclick();
	virtual void resetClick();
 */
void Click::resetClick(){
	isclicked=false;
	isrclicked=false;
}
void Click::click(){
	isclicked = true;
}
void Click::setNClicable()
{
	Options.isClicable=false;
}
void Click::setNRClicable(){
	Options.isRClicable = false;
}
} /* namespace ObjectSettings */
