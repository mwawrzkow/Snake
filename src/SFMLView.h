/*
 * SFMLView.h
 *
 *  Created on: 8 maj 2019
 *      Author: marcin
 */

#ifndef SRC_SFMLVIEW_H_
#define SRC_SFMLVIEW_H_
#include "WindowPrototypes/MSSFMLView.h"
namespace Window {

class SFML_View: public Graphic::SFML_Controler {
public:
	SFML_View();
};

} /* namespace Unit */

#endif /* SRC_SFMLVIEW_H_ */