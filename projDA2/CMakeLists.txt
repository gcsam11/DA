cmake_minimum_required(VERSION 3.24)
project(Project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project2 main.cpp Csv.cpp Csv.hpp Graph.cpp Graph.hpp Manager.cpp Manager.hpp Design.cpp Design.hpp Algorithms.cpp Algorithms.hpp)
