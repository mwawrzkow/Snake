/*
 * FileManager.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: marcin
 */

#include "FileManager.h"
#include <iostream>
#include <regex>
#include <iterator>

template<> char const* enumStrings<IO::Information>::data[] = { "W_width",
		"W_height", "M_Graphic_List", "G_Graphic_List" };

namespace IO {

FileManager::FileManager(const std::string filename) :
		filename(filename) {
	//SendToThread = new std::thread(IO_MultiThread::LFI, filename, &StoredInformation);
}
void FileManager::LoadFileInformation() {

}
IO::SingleInformation FileManager::LoadFileInformation(Information type) {
	//std::cout <<"File reading ended";
	return StoredInformation.ReturnInformation(type);
}
std::string FileManager::get_FileName() const {
	return filename;
}

void LFI(FileManager &temp) {
	std::ifstream file(temp.get_FileName());
	//std::cout << "starting reading the file" << std::endl;
	if (file.good()) {
		//	std::cout << "File has been opened!"<< std::endl;
	} else {
		std::cout << "File can't be open" << std::endl;
	}
	std::string line;
	std::regex world_regex("(\\S+)");
	while (std::getline(file, line)) {
		auto words_begin = std::sregex_iterator(line.begin(), line.end(),
				world_regex);
		auto words_end = std::sregex_iterator();
		/*
		 std::cout << "Found "
		 << std::distance(words_begin, words_end)
		 << " words\n";
		 */

		std::string name, ignorechar, values;
		int c = 0;
		for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
			std::smatch match = *i;
			std::string match_str = match.str();
			// std::cout << match_str <<std::endl;
			if (c == 0)
				name = match_str;
			if (c == 1)
				ignorechar = match_str;
			if (c == 2)
				values = match_str;
			c++;
		}

		std::stringstream tmp(name);
		IO::SingleInformation io;
		tmp >> enumFromString(io.name);
		io.value = values;
		temp.LFI_SET(io);
		//std::cout << io.name << std::endl << io.value << std::endl;

	}
	file.close();

}

void FileManager::LFI_SET(IO::SingleInformation &tmp) {
	StoredInformation.addInformation(tmp.name, tmp.value);
}
void FileManager::LFI_type(IO::SingleInformation &tmp, const char * name) {
	//std::string value(name);
	tmp.name = IO::Information::MENU_FILE_LIST;
	std::cout << enumToString(tmp.name);
	std::string tmpval(name);
	std::stringstream value(tmpval);
	IO::Information temp;
	value >> enumFromString(temp);
	tmp.name = temp;
}
void FileManager::LFI_value(IO::SingleInformation &tmp, const char * name) {
	tmp.value = name;
}

int FileManager::value_INT(Information type) {
	LoadFileInformation();
	IO::SingleInformation value;
	value = LoadFileInformation(type);
	//std::cout << value.name << std::endl << value.value <<std::endl;
	if (value.name < 0)
		return -1;
	int val = stoi(value.value);
	return val;
}
std::string FileManager::value_STR(Information type) {
	LoadFileInformation();
	IO::SingleInformation temp;
	temp = LoadFileInformation(type);
	return temp.value;
}
float FileManager::value_FLO(Information type) {
	LoadFileInformation();
	IO::SingleInformation temp;
	temp = LoadFileInformation(type);
	std::string::size_type size;
	return stof(temp.value, &size);
}
} /* namespace IO */

