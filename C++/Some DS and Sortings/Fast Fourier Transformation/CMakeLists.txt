cmake_minimum_required(VERSION 3.17)
project(Fast_Fourier_Transformation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(Fast_Fourier_Transformation main.cpp)