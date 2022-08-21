cmake_minimum_required(VERSION 3.10)

project(Bellman_Ford_&_Construct)
 
set(TASK main.cpp)
set(BIGOTIME  BigOTime/bigOTime.hpp)
set(BELLMAN_FORD  Bellman_Ford/graph.hpp)
set(CONSTRUCT  B_S_Construct/construct.hpp)

add_executable(tasks.out ${TASK} ${BIGOTIME} ${BELLMAN_FORD} ${CONSTRUCT})
