cmake_minimum_required(VERSION 3.17)
project(cf_702)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(cf_702 a.cpp)
add_executable(b b.cpp)
add_executable(c c.cpp)