cmake_minimum_required(VERSION 3.16)
set(C_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sub.cpp ${CMAKE_CURRENT_SOURCE_DIR}/sub.hpp)
add_library(c SHARED ${C_SOURCES})
