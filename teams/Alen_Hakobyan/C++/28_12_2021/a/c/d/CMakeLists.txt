cmake_minimum_required(VERSION 3.16)
set(D_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/mult.cpp ${CMAKE_CURRENT_SOURCE_DIR}/mult.hpp)
add_library(d SHARED ${D_SOURCES})
