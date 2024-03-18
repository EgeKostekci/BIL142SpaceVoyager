cmake_minimum_required(VERSION 3.27)
project(newProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(newProject main.cpp
        inc/event.h
        src/ship.cpp
        src/event.cpp
        inc/ship.h

)
