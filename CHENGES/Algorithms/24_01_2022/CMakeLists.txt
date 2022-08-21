cmake_minimum_required(VERSION 3.10)
project(Divide_&_Conquer)

set(TASKS main.cpp)
set(COMBINITION combinition.hpp)

add_executable(combinition.out ${TASKS} ${COMBINITION} )
