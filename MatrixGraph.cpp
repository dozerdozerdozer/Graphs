#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t verticesCount) : vertices_matrix_graph(verticesCount, std::vector<int>(verticesCount, 0)) {}

MatrixGraph::MatrixGraph(const IGraph& graph) : vertices_matrix_graph(graph.VerticesCount(), std::vector<int>(graph.VerticesCount(), 0)) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int nextVertex : graph.GetNextVertices(i)) {
            AddEdge(i, nextVertex);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    vertices_matrix_graph[from][to] = 1;
    vertices_matrix_graph[to][from] = 1;
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(vertices_matrix_graph.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (int i = 0; i < VerticesCount(); ++i) {
        if (vertices_matrix_graph[vertex][i] == 1) {
            nextVertices.push_back(i);
        }
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (int i = 0; i < VerticesCount(); ++i) {
        if (vertices_matrix_graph[i][vertex] == 1) {
            prevVertices.push_back(i);
        }
    }
    return prevVertices;
}
