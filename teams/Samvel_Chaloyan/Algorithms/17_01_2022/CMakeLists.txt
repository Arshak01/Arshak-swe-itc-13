cmake_minimum_required(VERSION 3.1)

project(sorting)

add_subdirectory(SelectionSort)
add_subdirectory(MergeSort)

add_executable(sorting main.cpp ${MERGE_SORT_SOURCES} ${SELECTION_SORT_SOURCES})
target_link_libraries(sorting SELECTION MERGE)
