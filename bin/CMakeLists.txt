cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++11)

set(NAME "mytest")
project(${NAME})
set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../)
set(CMAKE_MODULE_PATH ${PROJECT_ROOT}/cmake/Modules/)
message(STATUS ${CMAKE_MODULE_PATH})

set(myBST_ROOT /usr/local/myBST)
find_package(myBST)
find_package(Threads)

file(GLOB ${NAME}_HEADERS *.hpp)
file(GLOB ${NAME}_SOURCES *.cpp)

include_directories(${myBST_INCLUDE_DIRS})

add_executable(${NAME} ${${NAME}_HEADERS} ${${NAME}_SOURCES})

target_link_libraries(${NAME} pthread)
target_link_libraries(${NAME} myBST)
