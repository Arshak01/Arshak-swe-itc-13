cmake_minimum_required (VERSION 3.10)

set(E_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/mult.hpp ${CMAKE_CURRENT_SOURCE_DIR}/mult.cpp)
add_library(e SHARED ${E_SOURCES})
