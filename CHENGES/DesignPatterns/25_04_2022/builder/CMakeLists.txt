cmake_minimum_required(VERSION 3.16)
set(BUILDER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/builder.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/house.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/houseBuilder.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/manageHouse.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/manageHouseBuilder.cpp
)
add_library(builder SHARED ${BUILDER_SOURCES})
