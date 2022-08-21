cmake_minimum_required(VERSION 3.16)
set(PROXY_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/image.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/proxyImage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/realImage.cpp
)
add_library(proxy SHARED ${PROXY_SOURCES})
