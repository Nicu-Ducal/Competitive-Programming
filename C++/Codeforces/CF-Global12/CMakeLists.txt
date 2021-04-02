cmake_minimum_required(VERSION 3.17)
project(CF_Global12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(CF_Global12 main.cpp)
add_executable(other other.cpp)