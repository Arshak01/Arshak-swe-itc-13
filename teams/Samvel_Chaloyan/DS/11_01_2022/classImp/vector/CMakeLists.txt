cmake_minimum_required(VERSION 3.10)

project(vectorImp)

add_subdirectory(vectorClass)

add_executable(vectorImp main.cpp ${VECTOR_CLASS_SOURCES})
target_link_libraries(vectorImp VECTOR)
