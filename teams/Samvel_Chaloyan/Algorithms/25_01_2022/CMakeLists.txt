cmake_minimum_required(VERSION 3.1)

project(min_max)

add_subdirectory(MinMax)

add_executable(min_max main.cpp ${MINMAX_SOURCES})

target_link_libraries(min_max MINMAX)
