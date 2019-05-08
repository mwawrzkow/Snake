/*
 * FileManager.h
 *
 *  Created on: Mar 12, 2019
 *      Author: marcin
 */

#ifndef SRC_FILEMANAGER_H_
#define SRC_FILEMANAGER_H_
#include "FileInformation/FileInformation.h"

#include <fstream>
#include <string>
#include <thread>
#include <cstring>
#include <future>

namespace IO {

class FileManager {
	const std::string filename;
	FileInformation StoredInformation;
public:
	FileManager(const std::string filename);
	IO::SingleInformation LoadFileInformation(Information type);
	void LoadFileInformation();
	int value_INT(Information type);
	std::string value_STR(Information type);
	float value_FLO(Information type);
	std::string get_FileName()const;



	//Multithread
	void LFI_SET(IO::SingleInformation &tmp);;
protected:
	void LFI_type(IO::SingleInformation &tmp,const char * name);
	void LFI_value(IO::SingleInformation &tmp,const char* name);
};
void LFI(FileManager &temp);
} /* namespace IO */

#endif /* SRC_FILEMANAGER_H_ */
