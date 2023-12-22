#include "ArcGraph.h"

ArcGraph::ArcGraph(size_t verticesCount) {}

ArcGraph::ArcGraph(const IGraph& graph) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int nextVertex : graph.GetNextVertices(i)) {
            AddEdge(i, nextVertex);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    vertices_arc_graph.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    int maxVertex = 0;
    for (const auto& edge : vertices_arc_graph) {
        maxVertex = std::max(std::max(maxVertex, edge.first), edge.second);
    }
    return maxVertex + 1;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> nextVertices;
    for (const auto& edge : vertices_arc_graph) {
        if (edge.first == vertex) {
            nextVertices.push_back(edge.second);
        }
    }
    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prevVertices;
    for (const auto& edge : vertices_arc_graph) {
        if (edge.second == vertex) {
            prevVertices.push_back(edge.first);
        }
    }
    return prevVertices;
}
