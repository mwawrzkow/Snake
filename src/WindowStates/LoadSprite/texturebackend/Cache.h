/*
 * Cache.h
 *
 *  Created on: 26 mar 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_LOADSPRITE_TEXTUREBACKEND_CACHE_H_
#define SRC_WINDOWSTATES_LOADSPRITE_TEXTUREBACKEND_CACHE_H_

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <string>

namespace Texture {

class Cache {
	std::map<std::string,sf::Texture>TextureCache;
public:
	void addTexture(std::string name,sf::Texture temp);
	const bool doesTextureExist(std::string)const;
	sf::Texture* getTexture(std::string name);
};

} /* namespace Texture */

#endif /* SRC_WINDOWSTATES_LOADSPRITE_TEXTUREBACKEND_CACHE_H_ */
