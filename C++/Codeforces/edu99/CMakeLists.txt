cmake_minimum_required(VERSION 3.17)
project(edu99)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(edu99 main.cpp c.cpp)
add_executable(c c.cpp)