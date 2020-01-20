cmake_minimum_required(VERSION "3.7.1")

project("AAL-vururuk")

set(CMAKE_VERBOSE_MAKEFILE ON)


include_directories(${CMAKE_CURRENT_BINARY_DIR})
 



file(GLOB SOURCES "./*.cpp")
add_executable("$(PROJECT_NAME)" ${SOURCES})