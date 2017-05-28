cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++11)

set(NAME "mytest")
project(${NAME})
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(CMAKE_MODULE_PATH ${PROJECT_ROOT}/cmake/Modules/)

file(GLOB ${NAME}_HEADERS *.hpp)
file(GLOB ${NAME}_SOURCES *.cpp)

include_directories(../lib/)

add_executable(${NAME} ${${NAME}_HEADERS} ${${NAME}_SOURCES})
