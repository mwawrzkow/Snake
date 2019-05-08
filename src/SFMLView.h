/*
 * SFMLView.h
 *
 *  Created on: 8 maj 2019
 *      Author: marcin
 */

#ifndef SRC_SFMLVIEW_H_
#define SRC_SFMLVIEW_H_
#include "SnakeRender.h"
#include "WindowPrototypes/MSSFMLView.h"
#include "States/Game.h"
namespace Window {

class SFML_View: public Graphic::SFML_Controler {

public:
	SFML_View(SnakeRender&,IO::FileManager&,std::string);
};

} /* namespace Unit */

#endif /* SRC_SFMLVIEW_H_ */
