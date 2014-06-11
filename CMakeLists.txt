cmake_minimum_required(VERSION 2.8)
project( Kruskal )

include_directories(include)

add_library(graph graph.cpp)
add_executable (main main.cpp)
target_link_libraries (main graph)

