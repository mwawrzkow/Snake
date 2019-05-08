/*
 * SpriteOptions.cpp
 *
 *  Created on: 21 mar 2019
 *      Author: marcin
 */

#include "../texturebackend/SpriteOptions.h"

namespace SpriteSettings {

SpriteOptions::SpriteOptions(const char* name, int width, int height,int startingPos, int frames,int refreshRate) :
		name(name), width(width), height(height),startingPos(startingPos), frames(frames),swidth(width),sheight(height) {
}
const float SpriteOptions::getWidth() const {
	return width;
}
const float SpriteOptions::getHeight() const {
	return height;
}
const std::string SpriteOptions::getName() const {
	return name;
}
const int SpriteOptions::getFrameRate() const {
	return frames;
}
void SpriteOptions::frameCheckOut(int &requestedFrame)const
{
if(requestedFrame > frames)
	requestedFrame = 0;
}
const int SpriteOptions::getStartingPos()const{
	return startingPos;
}
void SpriteOptions::scale(float amount){
	sheight*=amount;
	swidth*=amount;

}
const float SpriteOptions::getsWidth()const{
	return swidth;
}
const float SpriteOptions::getsHeight()const{
	return sheight;
}
const bool SpriteOptions::isChanged()const{
	return hasChanged;
}
void SpriteOptions::changed(){
	hasChanged = !hasChanged;
}
} /* namespace SpriteSettings */
