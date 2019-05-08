/*
 * RenderClass.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: marcin
 */

#include "RenderClass.h"
#include "texturebackend/Cache.h"
#include <SFML/Graphics/Texture.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <Poco/NumberParser.h>
#include <Poco/String.h>

namespace WindowState {

RenderClass::RenderClass(std::string ConfigFile,
		std::shared_ptr<Texture::Cache> TextureCache) :
		ConfigFile(ConfigFile), Textures(
				TextureCache) {

}

void RenderClass::LoadTextureDirectories() {
	std::ifstream file(ConfigFile);
	std::cout << "starting reading the file" << std::endl << "from:"
			<< ConfigFile << std::endl;
	if (file.good()) {
		std::cout << "File has been opened!"<< std::endl;
	} else {
		std::cout << "File can't be open" << std::endl;
	}
	std::string line;
	ConfigFile.erase(ConfigFile.end() - 11, ConfigFile.end());
	while (std::getline(file, line)) {
		std::cout << "Trying to Create Sprite" << std::endl;
		std::vector<std::string> tokens = values(line);
		// Add Texture::Cache Implementation
		std::cout << "Tokens Taken" << std::endl;
		if(findTextureLoc(tokens.at(0)) == "ERROR")
		{
		addTexture(ConfigFile + tokens[0], tokens[0]);
		TexturesLink.push_back(tokens[0]);
		std::cout <<"Texture Created" << std::endl;
		}		Objects::Object* Sprite;
		Sprite = new Objects::Object;
		std::cout << "Sprite Pointer Created" << std::endl;
		Sprite->set(Textures->getTexture(tokens[0]),
				tokens[1].c_str(), Poco::NumberParser::parse(tokens[2]),
				Poco::NumberParser::parse(tokens[3]),
				Poco::NumberParser::parse(tokens[4]),
				Poco::NumberParser::parse(tokens[5]),
				Poco::NumberParser::parse(tokens[6]));
		std::cout << "Sprite Created!" << std::endl;
		int states = Poco::NumberParser::parse(tokens[7]);
		for (int i = states; i > 0; --i) {
			tokens.clear();
			std::getline(file, line);
			tokens = values(line);
			Sprite->addState(tokens[0].c_str(),
					Poco::NumberParser::parse(tokens[1]),
					Poco::NumberParser::parse(tokens[2]),
					Poco::NumberParser::parse(tokens[3]));
		}
		toRender.push_back(Sprite);
		std::cout << "Sprite Saved!" << std::endl;
		tokens.clear();
	}
	file.close();
	ClassState.isListLoaded = true;

}

std::string RenderClass::findTextureLoc(std::string tmp) {
	for (std::string temp : TexturesLink)
		if (Poco::icompare(tmp, temp) == 0)
			return temp;
	return "ERROR";
}

std::vector<std::string> RenderClass::values(std::string line) {
	std::vector<std::string> tmp;
	std::regex world_regex("(\\S+)");
	auto words_begin = std::sregex_iterator(line.begin(), line.end(),
			world_regex);
	auto words_end = std::sregex_iterator();
	int c = 0;
	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::smatch match = *i;
		std::string match_str = match.str();
		tmp.push_back(match_str);
		c++;
	}
	return tmp;

}

void RenderClass::addTexture(std::string File, std::string textureloc,
		bool isRepeated, bool isSmooth) {
	sf::Texture myPoorTexture;
	myPoorTexture.loadFromFile(textureloc);
	myPoorTexture.setRepeated(isRepeated);
	myPoorTexture.setSmooth(isSmooth);
	Textures->addTexture(File, myPoorTexture);
}

const ClassStates::state RenderClass::getState() const {
	return ClassState;
}
std::vector<Graphic::ObjectInterface*>& RenderClass::getQueue() {
	return toRender;
}
void RenderClass::addTexture(std::string fileLoc, std::string name) {
	if(Textures == nullptr)
		std::cout<<"Hallo Textura jest nullem!" << std::endl;
	sf::Texture tmp;
	tmp.loadFromFile(fileLoc);
	tmp.setRepeated(true);
	tmp.setSmooth(true);
	Textures->addTexture(name, tmp);
}
} /* namespace WindowState */
