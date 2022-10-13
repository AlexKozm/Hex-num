cmake_minimum_required (VERSION 3.10)
add_definitions("-Wall" "-g")
add_executable(lab3_run ./stat_hex_num.cpp ./main.cpp 
                        ./hex_num_abstract.cpp ./overl_stat_hex_num.cpp
                        ./hex_num_dynamic.cpp 
                        ./overl_dyn_hex_num.cpp)
