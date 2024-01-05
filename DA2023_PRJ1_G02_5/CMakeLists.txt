cmake_minimum_required(VERSION 3.23)
project(Project1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project1 code/main.cpp code/src/CsvLine.cpp code/include/CsvLine.h code/src/CsvReader.cpp code/include/CsvReader.h code/src/Station.cpp code/include/Station.h code/src/NetworkSegment.cpp code/include/NetworkSegment.h code/src/VertexEdge.cpp code/include/VertexEdge.h code/src/Manager.cpp code/include/Manager.h code/include/Design.h code/include/Graph.h code/src/Graph.cpp code/src/Design.cpp)
