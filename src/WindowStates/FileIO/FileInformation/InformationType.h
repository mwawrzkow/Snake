#ifndef INFORMATION_TYPE_H
#define INFORMATION_TYPE_H
#include "EnumStringConversion/EnumStringConversion.h"


namespace IO {

enum Information {
	WIDTH,
	HEIGHT,
	MENU_FILE_LIST,
	GAME_FILE_LIST,
};



struct SingleInformation {
Information name;
std::string value;
};

};

#endif
