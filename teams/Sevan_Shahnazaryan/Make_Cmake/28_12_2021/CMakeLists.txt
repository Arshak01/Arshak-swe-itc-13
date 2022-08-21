cmake_minimum_required(VERSION 3.10)

project(main)

#[[
**THIS VERSION ALSO WORKS**
set(PROD main.cpp prod/prod.cpp prod/prod.hpp)
set(SUM prod/sum/sum.cpp prod/sum/sum.hpp)
set(DIVI div/divi.cpp div/divi.hpp)
set(SUB div/sub/sub.cpp div/sub/sub.hpp)


add_executable(main ${PROD} ${SUM} ${DIVI} ${SUB})]]

add_subdirectory(prod)

file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/*.cpp
    ${CMAKE_SOURCE_DIR}/div/*.cpp
    ${CMAKE_SOURCE_DIR}/prod/sum/*.cpp
    ${CMAKE_SOURCE_DIR}/div/sub/*.cpp)

add_executable(main ${SOURCES} ${PROD_SOURCE})

#This is an example of using a library but I didn't implement it on every file
target_link_libraries(main prod)
