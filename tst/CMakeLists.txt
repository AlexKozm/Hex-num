find_package(Catch2 3 REQUIRED)

add_executable(tests curve-test.cpp )
target_link_libraries(tests PRIVATE Hex_num)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(tests_dyn curve-test-dyn.cpp )
target_link_libraries(tests_dyn PRIVATE Hex_num)
target_link_libraries(tests_dyn PRIVATE Catch2::Catch2WithMain)
