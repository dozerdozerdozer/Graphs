#include "SetGraph.h"

SetGraph::SetGraph(size_t verticesCount) : vertices_set_graph(verticesCount) {}

SetGraph::SetGraph(const IGraph& graph) : vertices_set_graph(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int nextVertex : graph.GetNextVertices(i)) {
            AddEdge(i, nextVertex);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    vertices_set_graph[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(vertices_set_graph.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    return std::vector<int>(vertices_set_graph[vertex].begin(), vertices_set_graph[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (int i = 0; i < VerticesCount(); ++i) {
        for (int nextVertex : vertices_set_graph[i]) {
            if (nextVertex == vertex) {
                prevVertices.push_back(i);
            }
        }
    }
    return prevVertices;
}
