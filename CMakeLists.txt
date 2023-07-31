cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME sfmlGame)

project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(libs/SFML-2.6.0)

add_subdirectory(UI)
add_subdirectory(CoreGame)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window CoreGame UI)
