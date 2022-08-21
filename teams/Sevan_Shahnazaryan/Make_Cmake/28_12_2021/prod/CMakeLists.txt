#To use a library(.so) for the prod.cpp file

cmake_minimum_required(VERSION 3.10)

set(PROD_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/prod.cpp ${CMAKE_CURRENT_SOURCE_DIR}/prod.hpp)
message(STATUS "PROD = " ${PROD_SOURCE})

add_library(prod SHARED ${PROD_SOURCE})
