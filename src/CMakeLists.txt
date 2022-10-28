cmake_minimum_required (VERSION 3.10)
add_definitions("-Wall" "-g")

add_executable(lab3_run 
  main.cpp 
  menu.cpp)
                        
target_link_libraries(lab3_run Hex_num)
