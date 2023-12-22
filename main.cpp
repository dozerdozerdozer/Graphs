#include <iostream>
#include <vector>
#include <queue>
// #include "ListGraph.h"
// #include "MatrixGraph.h"
#include "SetGraph.h"
// #include "ArcGraph.h"


void dfs_aux(int u, const IGraph &graph, std::vector<bool> &visited, void (*callback)(int v)) {
    visited[u] = true;
    callback(u);

    std::vector<int> children = graph.GetNextVertices(u);

    for (int v : children) {
        if (!visited[v]) {
            dfs_aux(v, graph, visited, callback);
        }
    }
}


int dfs(const IGraph &graph, void (*callback)(int v)) {
    int vertices_count = graph.VerticesCount();
    std::vector<bool> visited;

    visited.assign(vertices_count, false);
    for (int i = 0; i < vertices_count; ++i) {
        if (!visited[i]) {
            dfs_aux(i, graph, visited, callback);
        }
    }
}


void bfs_aux(int u, const IGraph &graph, std::vector<bool> &visited, void (*callback)(int v)) {
    std::queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        callback(v);

        std::vector<int> children = graph.GetNextVertices(u);
        for (int w : children) {
            if (!visited[w]) {
                visited[w] = true;
                q.push(w);
            }
        }
    }
}


int bfs(const IGraph &graph, void (*callback)(int v)) {
    int vertices_count = graph.VerticesCount();

    std::vector<bool> visited;

    visited.assign(vertices_count, false);
    for (int i = 0; i < vertices_count; ++i) {
        if (!visited[i]) {
            bfs_aux(i, graph, visited, callback);
        }
    }
}


int main() {
    // ListGraph graphL(6);
    // MatrixGraph graphM(6);
    // ArcGraph graphA(6);
    SetGraph graphS(6);


    graphS.AddEdge(0, 1);
    graphS.AddEdge(1, 0);

    graphS.AddEdge(1, 2);
    graphS.AddEdge(2, 1);

    graphS.AddEdge(2, 3);
    graphS.AddEdge(3, 2);

    graphS.AddEdge(2, 4);
    graphS.AddEdge(4, 2);

    graphS.AddEdge(3, 4);
    graphS.AddEdge(4, 3);


    dfs(graphS, [](int v) {
        std::cout << v << " ";
    });
    std::cout << std::endl;

    bfs(graphS, [](int v) {
        std::cout << v << " ";
    });
    std::cout << std::endl;

    std::cout << "OK" << std::endl;
}
