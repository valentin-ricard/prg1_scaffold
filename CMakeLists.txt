cmake_minimum_required(VERSION 3.16)
project(PRG_HEIG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

# ===
# IMPORTANT: The lines below are generated automatically generated using auto_make.py
# ===
#make:auto
add_executable(PRG_example ./src/example.cpp)
add_executable(PRG_repas ./src/repas.cpp)
#make:end