cmake_minimum_required(VERSION 3.27)
project(Slicer)

set(CMAKE_CXX_STANDARD 20)

set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB SOURCES LIST_DIRECTORIES FALSE *.cpp)

add_executable(${BINARY} ${SOURCES})