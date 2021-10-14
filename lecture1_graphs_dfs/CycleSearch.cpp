//
// Created by Grigoriy Khlytin on 14.10.2021.
//

#include "CycleSearch.h"

void CycleSearch::dfs(int u, int parent) {
    //красим вершину u в серый цвет
    vis[u] = 1;
    //проходим по всем соседям вершины u
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i]; //v - сосед u
        //если v еще не посещена, идем туда
        if (vis[v] == 0) {
            dfs(v, u);
        }
        if (vis[v] == 1 && v != parent) {
            //нашли цикл!
            flag = true;
        }
    }
    //красим вершину u в черный цвет
    vis[u] = 2;
}

void CycleSearch::solve() {
    int n, m;
    //считываем количество вершин и количество ребер соответственно
    std::cin >> n >> m;
    //устанавливаем размер векторов
    graph.resize(n);
    vis.resize(n);
    //считываем ребра неориентированного графа
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //обойдем граф DFS-ом
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0 && !flag) dfs(i, -1);
    }
    //вывод
    if (flag) {
        std::cout << "YES";
        return;
    }
    std::cout << "NO";
}
