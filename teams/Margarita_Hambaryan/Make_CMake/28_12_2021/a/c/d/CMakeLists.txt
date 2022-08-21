cmake_minimum_required (VERSION 3.10)

set(D_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/divv.hpp ${CMAKE_CURRENT_SOURCE_DIR}/divv.cpp)
add_library(d SHARED ${D_SOURCES})
