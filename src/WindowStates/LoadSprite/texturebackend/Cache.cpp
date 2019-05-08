/*
 * Cache.cpp
 *
 *  Created on: 26 mar 2019
 *      Author: marcin
 */

#include "Cache.h"
#include "iostream"
namespace Texture {


void Cache::addTexture(std::string name, sf::Texture temp) {
	TextureCache.insert(std::pair<std::string, sf::Texture>(name, temp));
	std::cout << "Created Texture named:" << name << std::endl;

}
sf::Texture* Cache::getTexture(std::string name) {
	return &TextureCache.find(name)->second;
	std::cout << "NOT FOUND" << std::endl;
	return nullptr;
}
const bool Cache::doesTextureExist(std::string name) const{
	std::map<std::string,sf::Texture>::const_iterator checker = TextureCache.find(name);
	return checker!=TextureCache.end();
}
} /* namespace Texture */
