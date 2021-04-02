cmake_minimum_required(VERSION 3.17)
project(CSES)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -g -Wfatal-errors -DLOCAL")

add_executable(CSES sum_of_two_values.cpp)
add_executable(maximum_subarray_sum maximum_subarray_sum.cpp)
add_executable(stick_lengths stick_lengths.cpp)
add_executable(missing_coin_sum missing_coin_sum.cpp)
add_executable(playlist playlist.cpp)
add_executable(counting_rooms counting_rooms.cpp)
add_executable(labyrinth labyrinth.cpp)