cmake_minimum_required(VERSION 3.27)
project(Slicer)

set(CMAKE_CXX_STANDARD 20)

set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false *.cpp)

add_executable(${BINARY} main.cpp ArgsParser.cpp ClientsReader.cpp)#${SOURCES})