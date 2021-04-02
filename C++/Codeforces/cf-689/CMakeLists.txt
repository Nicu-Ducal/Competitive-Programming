cmake_minimum_required(VERSION 3.17)
project(cf_689)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(cf_689 main.cpp)
add_executable(auxiliar auxiliar.cpp)