cmake_minimum_required(VERSION 3.5)

project("Dijkstras")

set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CXX_FLAGS "-O3")

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

file(GLOB SOURCES "src/*.cc")

add_executable(dijkstras src/main.cc)
