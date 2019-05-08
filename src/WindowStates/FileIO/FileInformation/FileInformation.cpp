/*
 * FIleInformation.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: marcin
 */

#include "FileInformation.h"

#include <iostream>
namespace IO {


FileInformation::FileInformation() {
	// TODO Auto-generated constructor stub

}
void FileInformation::addInformation(Information name, std::string value) {
	/*std::cout << "addInformation function" << std::endl
	*		<< "Information name:" << name<< std::endl
	*		<< "Information value:" << value << std::endl;
	*/
	SingleInformation temp;
	temp.name = name;
	temp.value = value;
	InformationStorage.push_back(temp);


}
int FileInformation::searchForInformation(Information name) {
	//std::cout << "Entering Searching loop" << std::endl;
	//std::cout << "InformationStorage size:" << InformationStorage.size() << std::endl;
	for (int i = 0; i < InformationStorage.size(); i++)
	{
		//std::cout << "Loop:" << i<< std::endl;
		//std::cout << "Element name:" << InformationStorage[i].name << std::endl;
		if (name == InformationStorage[i].name)
			return i;
	}
	return -1;
}
SingleInformation FileInformation::ReturnInformation(Information name) {
	//std::cout << "Returning information" << std::endl;
	int index = searchForInformation(name);
	//std::cout << "Index value:" << index << std::endl;
	SingleInformation error;
	error.value == "Error";
	if(index < 0)
		return error;
	SingleInformation temp;
	temp = InformationStorage[index];
	//std::cout << InformationStorage[index].name << std::endl << InformationStorage[index].value;
		return temp;

}
bool FileInformation::DeleteInformation(Information name) {
	int x = searchForInformation(name);
	if (x == -1)
		return false;
	InformationStorage.erase(InformationStorage.begin() + x);
	return true;
}

} /* namespace IO */

