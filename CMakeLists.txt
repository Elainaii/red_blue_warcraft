cmake_minimum_required(VERSION 3.27)
project(warCraft)

set(CMAKE_CXX_STANDARD 11)

add_executable(warCraft main.cpp
        warrior.cpp
        warrior.h
        gameManager.cpp
        gameManager.h
        headquarter.cpp
        headquarter.h
        weapon.h
        weapon.cpp
        Event.h
        Event.h
        Event.cpp)
