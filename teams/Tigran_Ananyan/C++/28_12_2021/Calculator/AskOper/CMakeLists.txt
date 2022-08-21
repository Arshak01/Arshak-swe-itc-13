cmake_minimum_required(VERSION 3.10)

set(OP_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/op.cpp ${CMAKE_CURRENT_SOURCE_DIR}/op.hpp)

add_library(op SHARED ${OP_SOURCE})


