cmake_minimum_required (VERSION 3.10)

set(PROJECT_NAME Hex_num)
 
project(${PROJECT_NAME})

set(SOURCE_FILES
  src/base/container.cpp
  src/base/hex_num.cpp
  src/dynamic/container_d.cpp
  src/dynamic/hex_num_d.cpp
  src/operators/operators.cpp
  src/static/container_s.cpp
  src/static/hex_num_s.cpp
  )
set(HEADER_FILES
  src/base/container.h 
  src/base/hex_num.h 
  src/dynamic/container_d.h 
  src/dynamic/hex_num_d.h 
  src/operators/operators.h 
  src/static/container_s.h 
  src/static/hex_num_s.h
  )
 
add_library(${PROJECT_NAME} STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC 
  src/base 
  src/static 
  src/dynamic 
  src/operators)

