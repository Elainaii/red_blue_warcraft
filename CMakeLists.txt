cmake_minimum_required(VERSION 3.27)
project(warCraft)

set(CMAKE_CXX_STANDARD 11)

add_executable(warCraft main.cpp
        knight.cpp
        knight.h
        gameManager.cpp
        gameManager.h
        headquarter.cpp
        headquarter.h)
