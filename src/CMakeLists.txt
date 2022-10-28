cmake_minimum_required (VERSION 3.10)
add_definitions("-Wall" "-g")

# find_package(Hex_num)
add_executable(lab3_run main.cpp 
                        # Hex_num/base/hex_num.cpp  
                        # Hex_num/base/container.cpp  
                        # Hex_num/operators/operators.cpp
                        # Hex_num/dynamic/hex_num_d.cpp 
                        # Hex_num/dynamic/container_d.cpp
                        # Hex_num/static/hex_num_s.cpp
                        # Hex_num/static/container_s.cpp
                        menu.cpp)
                        

target_link_libraries(lab3_run Hex_num)
# target_include_directories(lab3_run PUBLIC ./Hex_num)
# target_include_directories(lab3_run INTERFACE Hex_num)

# target_include_directories(lab3_run PUBLIC ./Hex_num/base)
# target_include_directories(lab3_run PUBLIC ./Hex_num/operators)
# target_include_directories(lab3_run PUBLIC ./Hex_num/static)
# target_include_directories(lab3_run PUBLIC ./Hex_num/dynamic)
