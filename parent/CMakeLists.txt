cmake_minimum_required(VERSION 3.1)

project(parent)

set(CMAKE_CXX_STANDARD 11)
set(SOURCES main.cpp parent.cpp utilities.cpp parent.h utilities.h)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(parent ${SOURCES})