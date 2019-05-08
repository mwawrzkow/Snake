/*
 * FIleInformation.h
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#ifndef SRC_WINDOWSTATES_FILEIO_FILEINFORMATION_FILEINFORMATION_H_
#define SRC_WINDOWSTATES_FILEIO_FILEINFORMATION_FILEINFORMATION_H_
#include <vector>
#include <string>

#include "InformationType.h"
namespace IO {

class FileInformation {
	std::vector<SingleInformation> InformationStorage;
public:
	FileInformation();
	void addInformation(Information name, std::string value);
	int searchForInformation(Information name);
	SingleInformation ReturnInformation(Information name);
	bool DeleteInformation(Information name);
};

} /* namespace IO */

#endif /* SRC_WINDOWSTATES_FILEIO_FILEINFORMATION_FILEINFORMATION_H_ */
