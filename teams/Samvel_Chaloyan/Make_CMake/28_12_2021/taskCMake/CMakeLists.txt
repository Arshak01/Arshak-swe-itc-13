cmake_minimum_required(VERSION 3.10)

project(calc)

add_subdirectory(div)
add_subdirectory(mod)
add_subdirectory(prod)
add_subdirectory(sum)
add_subdirectory(sub)


add_executable(calc calc.cpp ${DIV_SOURCES} ${MOD_SOURCES} ${PROD_SOURCES} ${SUM_SOURCES} ${SUB_SOURCES})
target_link_libraries(calc DIV MOD PROD SUB SUM)
