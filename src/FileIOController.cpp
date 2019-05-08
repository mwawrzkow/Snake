/*
 * FileIOController.cpp
 *
 *  Created on: 8 maj 2019
 *      Author: marcin
 */

#include "FileIOController.h"

namespace FileIO {

int lastslash(char findchar, std::string ourstring) {
	std::size_t temp;
	temp = ourstring.find_last_of(findchar);
	return temp;
}
void getexepath(const std::string lol, std::string &filelocation) {
	filelocation = lol;
	std::size_t whereami = lastslash(slash, filelocation);
	filelocation.erase(filelocation.begin() + (whereami + 1),
			filelocation.end());
}

} /* namespace FileIO */
