#include "ListGraph.h"

ListGraph::ListGraph(size_t vertices_count) {
    vertices_list_graph.resize(vertices_count);
}

void ListGraph::AddEdge(int from, int to) {
    vertices_list_graph[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return static_cast<int>(vertices_list_graph.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int v : vertices_list_graph[vertex]) {
        result.push_back(v);
    }
    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int from = 0; from < vertices_list_graph.size(); ++from) {
        for (int to : vertices_list_graph[from]) {
            if (to == vertex) {
                result.push_back(from);
            }
        }
    }
    return result;
}
