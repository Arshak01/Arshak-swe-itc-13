cmake_minimum_required(VERSION 3.10)

project(vector)

set(TASK main.cpp)
set(VECTOR vector.cpp)

add_executable(vector.out ${TASK} ${VECTOR})
