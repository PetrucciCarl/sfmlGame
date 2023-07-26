cmake_minimum_required(VERSION 3.8)

project(sfmlGame)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(".\\libs\\SFML-2.6.0")

add_executable(sfmlGame main.cpp main.cpp)

target_link_libraries(sfmlGame sfml-graphics sfml-system sfml-window)
