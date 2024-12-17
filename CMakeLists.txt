cmake_minimum_required(VERSION 3.29)
project(tetris_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(tetris_game main.cpp
        border.cpp
        border.h)
