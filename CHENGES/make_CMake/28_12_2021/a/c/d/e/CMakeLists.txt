cmake_minimum_required(VERSION 3.16)
set(E_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/mul.cpp ${CMAKE_CURRENT_SOURCE_DIR}/mul.hpp)
add_library(e SHARED ${E_SOURCES})
 
