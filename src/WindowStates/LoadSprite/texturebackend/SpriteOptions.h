/*
 * SpriteOptions.h
 *
 *  Created on: 21 mar 2019
 *      Author: Marcin Wawrzk��w
 *
 * Description: All settings of LoadSprite object
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_SPRITEOPTIONS_H_
#define SRC_WINDOWSTATES_LOADSPRITE_SPRITEOPTIONS_H_
#include <string>
namespace SpriteSettings {

class SpriteOptions {
	float width;
	float height;
	const std::string name;
	const int frames;
	const int startingPos;
	float swidth;
	float sheight;
	bool hasChanged = false;
public:
	SpriteOptions(const char* name, int width, int height, int startingPos,
			int frames, int refreshRate);
	const float getWidth() const;
	const float getHeight() const;
	const std::string getName() const;
	const int getFrameRate() const;
	void frameCheckOut(int &requestedFrame) const;
	const int getStartingPos() const;
	void scale(float x);
	const float getsWidth() const;
	const float getsHeight() const;
const	bool isChanged()const;
void changed();

};

} /* namespace SpriteSettings */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_SPRITEOPTIONS_H_ */
