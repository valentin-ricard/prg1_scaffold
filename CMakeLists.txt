cmake_minimum_required(VERSION 3.16)
project(PRG_HEIG)
include(CMakePrintHelpers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

# ==== Import single file executables ====
file(GLOB source_lists RELATIVE "${CMAKE_SOURCE_DIR}/src" "exo_*.cpp")

foreach (file_path ${source_lists})
    string(REPLACE ".cpp" "" new_name ${file_path})
    get_filename_component(filename ${new_name} NAME)
    add_executable(${filename} ${file_path})
endforeach ()

# === Import exercice folders ===
file(GLOB_RECURSE folder_source_lists RELATIVE ${CMAKE_SOURCE_DIR} "src/exo_*/main.cpp")
foreach (file_path ${folder_source_lists})
    get_filename_component(folder_tmp ${file_path} DIRECTORY)
    get_filename_component(folder ${folder_tmp} NAME)

    file(GLOB sources CONFIGURE_DEPENDS RELATIVE ${CMAKE_SOURCE_DIR} "${folder_tmp}/*.h" "${folder_tmp}/*.cpp")

    cmake_print_variables(folder_tmp sources)
    add_executable(${folder} ${sources})
endforeach ()

add_executable(TEST src/example.cpp)

# ===
# IMPORTANT: The lines below are generated automatically generated using auto_make.py
# ===
#make:auto#
#make:end