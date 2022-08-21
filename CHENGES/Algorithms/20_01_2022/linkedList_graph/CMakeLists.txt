cmake_minimum_required(VERSION 3.10)

project(DFS_BFS)

set(TASK main.cpp)
set(HELLO HelloWorld.hpp)
set(GRAPH ./DFS_BFS/graph.hpp)
set(EDGE ./DFS_BFS/edge.hpp)
set(VERTIC ./DFS_BFS/vertic.hpp)

add_executable(dfs_bfs.out ${TASK} ${HELLO} ${GRAPH} ${VERTIC} ${EDGE})
