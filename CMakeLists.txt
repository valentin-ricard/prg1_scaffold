cmake_minimum_required(VERSION 3.16)
project(PRG_HEIG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

file(GLOB_RECURSE source_lists RELATIVE ${CMAKE_SOURCE_DIR} "src/exo_*")

foreach (file_path ${source_lists})
    string(REPLACE ".cpp" "" new_name ${file_path})
    get_filename_component(filename ${new_name} NAME)
    add_executable( ${filename} ${file_path} )
endforeach ()

add_executable(TEST src/example.cpp)
# ===
# IMPORTANT: The lines below are generated automatically generated using auto_make.py
# ===
#make:auto#
#make:end