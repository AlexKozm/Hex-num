cmake_minimum_required (VERSION 3.10)

set(PROJECT_NAME Hex_num)
 
project(${PROJECT_NAME})

set(SOURCE_FILES
  base/container.cpp
  base/hex_num.cpp
  dynamic/container_d.cpp
  dynamic/hex_num_d.cpp
  operators/operators.cpp
  static/container_s.cpp
  static/hex_num_s.cpp
  )
set(HEADER_FILES
  base/container.h 
  base/hex_num.h 
  dynamic/container_d.h 
  dynamic/hex_num_d.h 
  operators/operators.h 
  static/container_s.h 
  static/hex_num_s.h
  )
 
# We declare the project as a static library and add all the source code files to it.
add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ./base 
                                                  ./static 
                                                  ./dynamic 
                                                  ./operators)

