cmake_minimum_required (VERSION 3.10)

set(TASK Task2_Brackets.cpp)
set(NODE Node.cpp)
set(STACK Stack.cpp)
set(CFUNC cfunc.cpp)

project(Brackets)

add_executable(Brackets ${TASK} ${NODE} ${STACK} ${CFUNC})
