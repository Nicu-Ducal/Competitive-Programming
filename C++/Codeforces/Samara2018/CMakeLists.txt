cmake_minimum_required(VERSION 3.17)
project(Samara2018)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(Samara2018 main.cpp)
add_executable(flow_version flow_version.cpp)