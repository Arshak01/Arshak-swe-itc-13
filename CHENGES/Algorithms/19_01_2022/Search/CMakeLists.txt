cmake_minimum_required(VERSION 3.10)
project(Searching)

set(TASKS main.cpp)
set(PRINT Print/print.hpp)
set(BIGOTIME BigOTime/bigOTime.hpp)
set(TERNARY Ternary/ternary.hpp)
set(INTERPOLATION Interpolation/interpolation.hpp)
set(EXPONENTAL Exponental/exponental.hpp)
set(QUICK Quick/quickSort.hpp)

add_executable(sorts.out ${TASKS} ${PRINT} ${TERNARY} ${INTERPOLATION} ${EXPONENTAL} ${BIGOTIME} ${QUICK} )
