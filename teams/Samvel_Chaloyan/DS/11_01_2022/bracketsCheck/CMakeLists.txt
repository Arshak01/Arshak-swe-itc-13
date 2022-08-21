cmake_minimum_required(VERSION 3.1)

project(bracketsCheck)

add_subdirectory(classNode)
add_subdirectory(classStack)
add_subdirectory(expCheck)

add_executable(bracketsCheck main.cpp ${NODE_CLASS_SOURCES} ${STACK_CLASS_SOURCES} ${CHECK_FUNCTION_SOURCES})
target_link_libraries(bracketsCheck STACK NODE)##CHECK)
