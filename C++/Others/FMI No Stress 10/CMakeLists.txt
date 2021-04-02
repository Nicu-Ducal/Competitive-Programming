cmake_minimum_required(VERSION 3.17)
project(FMI_No_Stress_10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(FMI_No_Stress_10 domenii.cpp)
add_executable(loterie loterie.cpp)
add_executable(prieteni2 prieteni2.cpp)
add_executable(drum7 drum7.cpp)
add_executable(margiki margiki.cpp)
add_executable(stv stv.cpp)