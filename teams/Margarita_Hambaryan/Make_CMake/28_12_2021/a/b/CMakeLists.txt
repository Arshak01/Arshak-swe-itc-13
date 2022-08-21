cmake_minimum_required (VERSION 3.10)

set(B_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sum.hpp ${CMAKE_CURRENT_SOURCE_DIR}/sum.cpp)
add_library(b SHARED ${B_SOURCES})
