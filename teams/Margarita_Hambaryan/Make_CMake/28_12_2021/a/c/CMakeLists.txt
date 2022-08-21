cmake_minimum_required (VERSION 3.10)

set(C_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sub.hpp ${CMAKE_CURRENT_SOURCE_DIR}/sub.cpp)
add_library(c SHARED ${C_SOURCES})
