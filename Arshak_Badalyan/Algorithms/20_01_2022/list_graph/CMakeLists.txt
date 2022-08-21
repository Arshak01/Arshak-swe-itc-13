cmake_minimum_required(VERSION 3.10)
project(BFS_DFS)

set(TASK main.cpp)
set(GRAPH_HPP ./graph.hpp)
set(GRAPH_CPP ./graph.cpp)

add_executable(dfs_bfs.out ${TASK} ${GRAPH_HPP} ${GRAPH_CPP})
