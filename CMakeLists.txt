cmake_minimum_required(VERSION 3.30)
project(finite_difference)

set(CMAKE_CXX_STANDARD 20)

find_package(Catch2 3 REQUIRED)

add_executable(finite_diff src/main.cpp)
add_executable(example_10.2 src/example_10.2.cpp)
target_link_libraries(finite_diff m)

add_executable(tests src/tests.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
