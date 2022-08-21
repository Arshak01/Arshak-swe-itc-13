cmake_minimum_required(VERSION 3.10)
set(MULT_SOURCES mult.cpp)
add_library(mult SHARED %{MULT_SOURCES})
