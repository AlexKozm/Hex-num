cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(./src)

add_subdirectory(./libs/Hex_num)
add_subdirectory(./src)
add_subdirectory(./tst)
