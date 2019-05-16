/*
 * Game.h
 *
 *  Created on: May 8, 2019
 *      Author: mwawrzkow
 */

#ifndef SRC_STATES_GAME_H_
#define SRC_STATES_GAME_H_
#include "../WindowStates/State.h"
#include "../GameLogic/Snake/GameController.h"
#include "Game/Tile.h"
namespace SnakeState {

class Game: public Controller::State {
private:
	std::vector<Unit::Tile *>brick;
	std::vector<Unit::Tile *>board;
	Unit::Tile *eatable;
	Unit::Tile *snakeface;
	std::vector<Unit::Tile *> snakebody;
	Controller::GameController *GameControler;
	sf::Clock clock;
	bool firstMove = false;
	int SnakeLenght= 1;
public:
	Game(std::string, std::shared_ptr<Texture::Cache> TextureCache, bool*);
	virtual ~Game();
	virtual void CreateUnits();
	virtual void setUnits();
	virtual void update(Unit::move) override;
	virtual void update()override;
	void UnitsUpdate();
};

} /* namespace Window */

#endif /* SRC_STATES_GAME_H_ */
