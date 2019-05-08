cmake_minimum_required (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -lpthread -lstdc++ -lX11")
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})

project (Snake)


find_package(Poco REQUIRED COMPONENTS Foundation Net Zip )
find_package(SFML  REQUIRED graphics window system)


add_executable(Snake 
					Snake.cpp
					src/GameLogic/Snake/Grid/SnakeBoard.cpp
					src/GameLogic/Snake/Grid/Snake.cpp
					src/GameLogic/Snake/Player.cpp
					src/GameLogic/Snake/GameController.cpp
					
					src/WindowStates/FileIO/FileInformation/FileInformation.cpp
					src/WindowStates/FileIO/FileManager.cpp
					
					src/WindowStates/LoadSprite/texturebackend/Cache.cpp
					src/WindowStates/LoadSprite/texturebackend/SpriteOptions.cpp
					
					src/WindowStates/LoadSprite/ClickEvent.cpp
					src/WindowStates/LoadSprite/Object.cpp
					src/WindowStates/LoadSprite/ObjectInterface.cpp
					src/WindowStates/LoadSprite/ObjectUpdate.cpp
					src/WindowStates/LoadSprite/RenderClass.cpp
	
					src/WindowStates/State.cpp
					
					src/WindowPrototypes/EventHandler.cpp
					src/WindowPrototypes/MSSFMLView.cpp
					src/WindowPrototypes/Render.cpp
					src/FileIOController.cpp
					src/SFMLView.cpp
					
					)
					
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Snake ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    target_link_libraries(Snake sfml-system sfml-window sfml-graphics sfml-audio)
    
endif()
target_link_libraries(Snake Poco::Foundation Poco::Util Poco::Net)
					
