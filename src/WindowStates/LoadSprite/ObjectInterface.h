/*
 * LoadSprite.h
 *
 *  Created on: Mar 13, 2019
 *      Author: Marcin Wawrzk��w
 *
 *
 * Description: LoadSprite Class:
 *                         * Holds sf::SpriteObject.
 *              Functionality:
 *                         * Update Sprite frame by frame.
 *                         * Allows to return sprite by reference to render.
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_OBJECTINTERFACE_H_
#define SRC_WINDOWSTATES_LOADSPRITE_OBJECTINTERFACE_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "ClickEvent.h"
#include "texturebackend/SpriteOptions.h"


namespace Graphic {

class ObjectInterface: public ObjectSettings::Click {
protected:
	sf::Sprite Sprite;
	std::vector<SpriteSettings::SpriteOptions>states;
	int state = 0;
	sf::Clock elapsedTime;
private:
	int maxStates = 0;
	int frame = 0;
	bool Visible = true;
public:
	virtual void createSprite();
	virtual void spriteUpdate();
	virtual void update() = 0;
	virtual  sf::Sprite* returnSprite();
	virtual void addState(std::string name, int startingpos, int frames,int frameRate);
	virtual void updateState(std::string);
	virtual void setPosition(float,float) = 0;
	ObjectInterface();
	virtual ~ObjectInterface();
	virtual void set(sf::Texture *ref,const char* name, int width, int height, int startingPos, int frames,int refreshRate);
	virtual std::string getName();
	virtual SpriteSettings::SpriteOptions getSpriteOptions();
	virtual void toggleVisible();
	virtual bool isVisible();
	virtual void resetState();
};

} /* namespace Graphic */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_OBJECTINTERFACE_H_ */
