/*
 * Object.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#include "ObjectInterface.h"

#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <string>
#include <vector>

namespace Graphic {
ObjectInterface::ObjectInterface(){ // @suppress("Class members should be properly initialized")
}
void ObjectInterface::set(sf::Texture *ref, const char* name, int width, int height,
		int startingPos, int frames, int refreshRate){
	SpriteSettings::SpriteOptions Settings(name, width, height, startingPos,
			frames, refreshRate);
	Sprite.setTexture(*ref);
	states.push_back(Settings);
}

void ObjectInterface::createSprite() {
	if (state <= maxStates && state >= 0)
		Sprite.setTextureRect(
				sf::IntRect(0, states[state].getStartingPos(), states[state].getWidth(),
						states[state].getHeight()));
}
void ObjectInterface::spriteUpdate() {
	states[state].frameCheckOut(frame);
	int update = frame+1;
	states[state].frameCheckOut(update);
	Sprite.setTextureRect(
			sf::IntRect(states[state].getWidth() * frame,
					states[state].getStartingPos(),
					states[state].getWidth() * update,
					states[state].getHeight()));
}
sf::Sprite* ObjectInterface::returnSprite() {
	return &Sprite;
}

void ObjectInterface::addState(std::string name, int startingpos, int frames,int frameRate) {

	SpriteSettings::SpriteOptions Settings(name.c_str(), states[0].getWidth(),
			states[0].getHeight(), startingpos, frames,frameRate);
	std::cout << "Created sprite state :" << Settings.getName() << std::endl
			<< "height: " << Settings.getHeight() << std::endl << "Width: "
			<< Settings.getWidth() << std::endl << "startingPos: "
			<< Settings.getStartingPos() << std::endl << "Framerate: "
			<< Settings.getFrameRate() << std::endl;
	states.push_back(Settings);
	++maxStates;
}

std::string ObjectInterface::getName(){
return states[state].getName();
}
ObjectInterface::~ObjectInterface(){
}
SpriteSettings::SpriteOptions ObjectInterface::getSpriteOptions()
{
	return states[state];
}
void ObjectInterface::toggleVisible(){
	Visible = !Visible;
}
bool ObjectInterface::isVisible(){
	return Visible;
}
void ObjectInterface::updateState(std::string state){
}

void ObjectInterface::resetState(){
	this->state = 0;
}
} /* namespace Graphic */
