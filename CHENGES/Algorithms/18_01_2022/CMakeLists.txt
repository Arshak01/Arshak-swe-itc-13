cmake_minimum_required(VERSION 3.10)
project(Algorithms)
 
set(SHELL Shell/shellSort.hpp)
set(QUICK  Quick/quickSort.hpp)
set(BIGOTIME  BigOTime/bigOTime.hpp)
set(PRINT Print/print.hpp)
set(TASK main.cpp)
add_executable(sorts.out ${TASK} ${PRINT} ${BIGOTIME} ${SHELL} ${QUICK})
