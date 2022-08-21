cmake_minimum_required(VERSION 3.10)

project(checkBrackets)

set(MAIN main.cpp)
set(BRACKETS checkBrackets.cpp)

add_executable(brackets.out ${MAIN} ${BRACKETS})
