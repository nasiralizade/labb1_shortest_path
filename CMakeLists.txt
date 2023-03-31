cmake_minimum_required(VERSION 3.24)
project(labb1)

set(CMAKE_CXX_STANDARD 20)

add_executable(labb1 main.cpp reader.cpp reader.h Dfs.cpp Dfs.h Dijkstras.cpp Dijkstras.h Bfs.cpp Bfs.h)
