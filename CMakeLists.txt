cmake_minimum_required(VERSION 3.24)
project(network_flow)

set(CMAKE_CXX_STANDARD 17)

add_executable(network_flow main.cpp Flow_Graph.h Flow_Graph.cpp)
