cmake_minimum_required(VERSION 3.21)
project(ex2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex2
        Card.h
        Card.cpp
        Mtmchkin.h
        Mtmchkin.cpp
        Player.cpp
        Player.h
        test.cpp
        utilities.cpp
        utilities.h)
