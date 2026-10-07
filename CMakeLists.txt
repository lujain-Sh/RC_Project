cmake_minimum_required(VERSION 3.12)
project(PuzzleArcade CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# New .cpp files in games/ are picked up automatically (re-run CMake / reload the project).
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/main.cpp
     ${CMAKE_SOURCE_DIR}/games/*.cpp)

add_executable(arcade ${SOURCES})
