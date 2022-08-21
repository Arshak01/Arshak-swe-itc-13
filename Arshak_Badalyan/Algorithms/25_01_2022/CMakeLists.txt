cmake_minimum_required(VERSION 3.10)
project(Min_&_Max)

set(TASKS main.cpp)
set(PRINT print.hpp)
set(MINMAX minMax.hpp)

add_executable(minMax.out ${TASKS} ${PRINT} ${MINMAX})
