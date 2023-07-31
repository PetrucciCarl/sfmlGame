cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME CoreGame)

project(${PROJECT_NAME} VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(HEADER_FILES    Food.hpp
                    Snake.hpp)

set(SOURCE_FILES    Food.cpp
                    Snake.cpp)

include_directories(../libs/SFML-2.6.0/include)

add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME} sfml-graphics)