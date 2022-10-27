find_package(Catch2 3 REQUIRED)

add_executable(tests curve-test.cpp 
                     ../src/Hex_num/base/hex_num.cpp
                     ../src/Hex_num/base/container.cpp
                     ../src/Hex_num/static/hex_num_s.cpp 
                     # ../src/Hex_num/static/overl_stat_hex_num.cpp
                     )
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(tests_dyn curve-test-dyn.cpp 
                     ../src/Hex_num/base/hex_num.cpp
                     ../src/Hex_num/base/container.cpp
                     ../src/Hex_num/dynamic/hex_num_d.cpp 
                     ../src/Hex_num/dynamic/container_d.cpp
                     # ../src/Hex_num/dynamic/overl_dyn_hex_num.cpp
                     )
target_link_libraries(tests_dyn PRIVATE Catch2::Catch2WithMain)
