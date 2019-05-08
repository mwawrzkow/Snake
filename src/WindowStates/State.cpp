/*
 * StateController.cpp
 *
 *  Created on: Apr 25, 2019
 *      Author: mwawrzkow
 */

#include "State.h"

namespace Controller {

void State::StateAdd(std::string tmp) {
	availibeNames.push_back(tmp);
	// TODO Auto-generated constructor stub

}
State::State(std::string FileList,std::shared_ptr<Texture::Cache>TextureCache, bool* sendRequest):
		Render(FileList + "config.conf", TextureCache),sendRequest(sendRequest)
		{		}
State::~State() {
	availibeNames.clear();
	// TODO Auto-generated destructor stub
}
void State::update(){
	for(Graphic::ObjectInterface *e:Units)
		e->spriteUpdate();
}
std::vector<Graphic::ObjectInterface*>*State::getUnits(){
	return &Units;
}
void State::resetStates(){
	for(Graphic::ObjectInterface *e:Units)
		e->resetState();
}
GameState::State State::AskedState(){
return askState;
}
void State::LoadFiles(){
	Render.LoadTextureDirectories();
}
void State::start() {
	LoadFiles();
	CreateUnits();
	setUnits();
}
} /* namespace Controller */
