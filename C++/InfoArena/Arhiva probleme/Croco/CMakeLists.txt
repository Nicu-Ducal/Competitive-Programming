cmake_minimum_required(VERSION 3.17)
project(Croco)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(Croco main.cpp)
add_executable(dinic dinic.cpp)
add_executable(alta_solutie alta_solutie.cpp)