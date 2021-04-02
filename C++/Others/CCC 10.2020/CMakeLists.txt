cmake_minimum_required(VERSION 3.17)
project(CCC_10_2020)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(CCC_10_2020 main.cpp)
add_executable(level4 level4.cpp)
add_executable(level5 level5.cpp)