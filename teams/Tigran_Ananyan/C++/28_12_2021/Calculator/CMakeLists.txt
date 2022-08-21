cmake_minimum_required(VERSION 3.10)

project(main)

add_subdirectory(AskOper)

file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/*.cpp
    ${CMAKE_SOURCE_DIR}/AskOper/*.cpp
    ${CMAKE_SOURCE_DIR}/AskOper/AskNum/*.cpp
    ${CMAKE_SOURCE_DIR}/AskOper/AskNum/CalcFunction/*.cpp)

add_executable(main ${SOURCES} ${OP_SOURCE})

target_link_libraries(main op)
