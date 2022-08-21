cmake_minimum_required(VERSION 3.16)
file(GLOB SOURCES *)
add_subdirectory(b)
add_subdirectory(c)
add_subdirectory(c/d)
add_subdirectory(c/d/e)
add_executable(main ${SOURCES})
target_link_libraries(main b c d e)

 
