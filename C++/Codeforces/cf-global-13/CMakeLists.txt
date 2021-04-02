cmake_minimum_required(VERSION 3.17)
project(cf_global_13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(cf_global_13 A.cpp)
add_executable(B B.cpp)
add_executable(C C.cpp)
add_executable(D D.cpp)