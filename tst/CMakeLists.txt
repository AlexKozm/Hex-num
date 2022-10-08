find_package(Catch2 3 REQUIRED)

add_executable(tests curve-test.cpp 
                     ../src/stat_hex_num.cpp 
                     ../src/hex_num_abstract.cpp
                     ../src/overl_stat_hex_num.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
