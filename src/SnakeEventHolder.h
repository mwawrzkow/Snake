/*
 * SnakeEventHolder.h
 *
 *  Created on: May 11, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_SNAKEEVENTHOLDER_H_
#define SRC_SNAKEEVENTHOLDER_H_
#include "WindowPrototypes/EventHandler.h"
namespace GraphicEvents {

class SnakeEventHolder : public SFML_Handlers::EventHandler{
public:
	SnakeEventHolder(Poco::Mutex *renderMutex);
	virtual ~SnakeEventHolder();
protected:
	virtual void EventChecker() override;
	void KeyPressed();
};

} /* namespace GraphicEvents */

#endif /* SRC_SNAKEEVENTHOLDER_H_ */
