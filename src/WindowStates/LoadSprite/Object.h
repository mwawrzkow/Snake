/*
 * Object.h
 *
 *  Created on: Apr 24, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_OBJECT_H_
#define SRC_WINDOWSTATES_LOADSPRITE_OBJECT_H_
#include "ObjectInterface.h"
namespace Objects {

class Object : public Graphic::ObjectInterface {
public:
	virtual void update();
	virtual ~Object();
	virtual void setPosition(float,float);
	virtual void updateState(std::string);
};

} /* namespace Objects */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_OBJECT_H_ */
