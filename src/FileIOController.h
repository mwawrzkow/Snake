/*
 * FileIOController.h
 *
 *  Created on: 8 maj 2019
 *      Author: marcin
 */

#ifndef SRC_FILEIOCONTROLLER_H_
#define SRC_FILEIOCONTROLLER_H_
#include <string>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
const char slash = 0x5C;

#else
const char slash = 0x2F;

#endif
namespace FileIO {


int lastslash(char findchar, std::string ourstring);

void getexepath(const std::string lol, std::string &filelocation);


} /* namespace FileIO */

#endif /* SRC_FILEIOCONTROLLER_H_ */
