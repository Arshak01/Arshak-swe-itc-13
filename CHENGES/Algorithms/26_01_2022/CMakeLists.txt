cmake_minimum_required(VERSION 3.10)
project(Ugly_numbers)

set(TASKS main.cpp)
set(BIGOTIME BigOTime/bigOTime.hpp)
set(UGLY_REC Ugly/recursion.hpp)
set(UGLY_WHILE Ugly/whileLoop.hpp)
set(UGLY_FOR Ugly/forLoop.hpp)

add_executable(ugly.out ${TASKS} ${UGLY_WHILE} ${UGLY_REC} ${UGLY_FOR})
