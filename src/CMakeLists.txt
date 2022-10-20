cmake_minimum_required (VERSION 3.10)
add_definitions("-Wall" "-g")
add_executable(lab3_run main.cpp 
                        Hex_num/base/hex_num.cpp  
                        Hex_num/base/container.cpp  
                        Hex_num/dynamic/hex_num_dynamic.cpp 
                        Hex_num/dynamic/overl_dyn_hex_num.cpp
                        Hex_num/static/stat_hex_num.cpp
                        Hex_num/static/overl_stat_hex_num.cpp
                        menu.cpp)
                        
target_include_directories(lab3_run PUBLIC ./Hex_num/base)
target_include_directories(lab3_run PUBLIC ./Hex_num/static)
target_include_directories(lab3_run PUBLIC ./Hex_num/dynamic)
