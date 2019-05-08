#include <iostream>
#include "src/FileIOController.h"
#include "src/SFMLView.h"

int main(int argc, char **argv) {
	/*
	std::string ConfigurationFilePath;
	FileIO::getexepath(argv[0], ConfigurationFilePath);
	IO::FileManager settings(ConfigurationFilePath + "Config.conf");
	LFI(settings);
	sf::RenderWindow toController(
			sf::VideoMode(settings.value_INT(IO::Information::WIDTH),
					settings.value_INT(IO::Information::HEIGHT)), "Snake");
	Window::SnakeRender render(toController);
	Window::SFML_View Window(render,settings,ConfigurationFilePath);
	*/
	Controller::GameController ctrl("Marcinek");
	ctrl.debugStart();
	return 0;
}
