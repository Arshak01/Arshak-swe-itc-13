cmake_minimum_required(VERSION 3.10)

project(Vector)

set(TASK Task1_Vector.cpp)
set(VECTOR Vector.cpp)

add_executable(Vector ${TASK} ${VECTOR})
