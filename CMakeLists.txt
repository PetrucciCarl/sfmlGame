cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME sfmlGame)

project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES    Food.cpp
                    Game.cpp
                    GameMenu.cpp
                    MainMenu.cpp
                    Snake.cpp)

set(HEADER_FILES    Engine.hpp
                    Food.hpp
                    Game.hpp
                    GameMenu.hpp
                    MainMenu.hpp
                    Snake.hpp)

add_subdirectory(libs/SFML-2.6.0)
include_directories(libs/SFML-2.6.0/include)

add_subdirectory(libs/json-3.11.2)
include_directories(libs/json-3.11.2/include)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} main.cpp)

target_link_libraries(${PROJECT_NAME} sfml-graphics nlohmann_json)
