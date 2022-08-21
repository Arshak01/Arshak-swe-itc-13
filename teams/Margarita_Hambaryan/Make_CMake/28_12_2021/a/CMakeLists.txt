cmake_minimum_required (VERSION 3.10)
project(test)
add_subdirectory(b)
add_subdirectory(c)
add_subdirectory(c/d)
add_subdirectory(c/d/e)
file(GLOB SOURCES *)

add_executable(test main.cpp ${SOURCES})

target_link_libraries(test b c d e)
