/*
 * ClickEvent.h
 *
 *  Created on: 13 kwi 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_CLICKEVENT_H_
#define SRC_WINDOWSTATES_LOADSPRITE_CLICKEVENT_H_
namespace Graphic {
class ObjectInterface;
} /* namespace Graphic */
namespace sf {
class Event;
} /* namespace sf */


namespace ObjectSettings {
	struct ClickOptions{
		bool isClicable,isHoverable,isRClicable;
		ClickOptions();
	};

class Click {
private:
		bool isclicked=false,isrclicked=false;
		ClickOptions Options;
public:
	void ToggleClicable();
	void ToggleHoverable();
	void ToggleRClicable();
	Click();
	ClickOptions* ClickEvent();
	virtual bool checkClick();
	virtual void click();
	virtual void rclick();
	virtual bool checkrClick();
	virtual void setNClicable();
	virtual void setNRClicable();
	//virtual void hover();
	//virtual void rclick();
	virtual void resetClick();
	virtual ~Click();

};

} /* namespace ObjectSettings */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_CLICKEVENT_H_ */
