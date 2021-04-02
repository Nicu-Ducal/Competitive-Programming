cmake_minimum_required(VERSION 3.17)
project(Cuplaj_maxim_in_graf_bipartit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(Cuplaj_maxim_in_graf_bipartit main.cpp)
add_executable(dinic_matching dinic_matching.cpp)