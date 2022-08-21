cmake_minimum_required(VERSION 3.1)

project(ternarSearch)

add_subdirectory(ShellSort)
add_subdirectory(TernarySearch)

add_executable(ternarSearch main.cpp ${SHELL_SORT_SOURCES} ${TERNARY_SEARCH+SOURCES})

target_link_libraries(ternarSearch SHELL_SORT TERNARY_SEARCH)
