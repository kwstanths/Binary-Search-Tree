cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++11)

set(NAME "myBST")
project(${NAME})

file(GLOB ${NAME}_HEADERS *.hpp)
file(GLOB ${NAME}_SOURCES *.cpp)

add_library(${NAME} ${${NAME}_HEADERS})
set_target_properties(${NAME} PROPERTIES LINKER_LANGUAGE CXX)

install(TARGETS ${NAME} DESTINATION ${NAME}/lib)
install(FILES ${${NAME}_HEADERS} DESTINATION ${NAME}/include) 
