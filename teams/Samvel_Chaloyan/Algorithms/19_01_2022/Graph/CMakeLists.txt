cmake_minimum_required(VERSION 3.1)

project(graphRepresentation)

add_subdirectory(GraphMatrix)
add_subdirectory(GraphHashMap)

add_executable(graphRepresentation main.cpp ${GRAPH_HASHMPA_SOURCES} ${GRAPG_MATRIX_SOURCES})

target_link_libraries(graphRepresentation GRAPH_HASHMAP GRAPH_MATRIX)
