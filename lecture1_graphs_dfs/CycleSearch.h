//
// Created by Grigoriy Khlytin on 14.10.2021.
//

#include <iostream>
#include <vector>

#ifndef ITMO_CIRCLE_B_DIST_CYCLESEARCH_H
#define ITMO_CIRCLE_B_DIST_CYCLESEARCH_H

class CycleSearch {
public:
    //список смежности
    std::vector<std::vector<int>> graph;
    //массив посещений
    std::vector<int> vis;
    //флаг, есть ли цикл в графе
    bool flag = false;

    //реализация метода помещена в файл CycleSearch.cpp
    void dfs(int u, int parent);

    //реализация метода помещена в файл CycleSearch.cpp
    void solve();
};

#endif //ITMO_CIRCLE_B_DIST_CYCLESEARCH_H
