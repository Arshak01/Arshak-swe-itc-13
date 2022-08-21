cmake_minimum_required(VERSION 3.10)
project(Graph)

set(TASKS main.cpp)
set(MATRIX Matrix/matrix.hpp)

add_executable(graph.out ${TASKS} ${MATRIX} )
