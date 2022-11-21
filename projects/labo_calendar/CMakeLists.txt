cmake_minimum_required(VERSION 3.16)
project(LABO_CALENDAR)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(MAIN ./src/main.cpp)
