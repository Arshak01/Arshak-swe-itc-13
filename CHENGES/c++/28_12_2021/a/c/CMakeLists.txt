cmake_minimum_required(VERSION 3.16)
set(C_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sum.cpp ${CMAKE_CURRENT_SOURCE_DIR}/sum.hpp)
add_library(c SHARED ${C_SOURCES})
 
