cmake_minimum_required(VERSION 3.16)
project(itmo_circle_B_dist)

set(CMAKE_CXX_STANDARD 17)

add_executable(itmo_circle_B_dist
        main.cpp
        lecture1_graphs_dfs/CycleSearch.cpp
        lecture1_graphs_dfs/CycleSearch.h
        lecture_search_tree/SearchTree.h
        lecture_search_tree/SearchTree.cpp)
