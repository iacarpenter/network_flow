#include <queue>
#include "Flow_Graph.h"

FlowGraph::FlowGraph(std::size_t v, int source, int sink) {
    for (int i = 0; i < v; ++i)
        vertices.push_back(Vertex(i));

    vertex_count = v;
    this->source = source;
    this->sink = sink;
}

FlowGraph::Edge::Edge(int f, int t, int c, bool reverse) {
    from = f;
    to = t;
    capacity = c;
    is_reverse = reverse;
}

FlowGraph::Vertex::Vertex(int i) {
    id = i;
}

void FlowGraph::add_edge(int from, int to, int capacity) {
    vertices[from].edges.push_back(Edge(from, to, capacity));
}

int FlowGraph::max_flow() {
    while (bfs()) {
        
    }
}

bool FlowGraph::bfs() {
    std::queue<int> q;
    std::vector<int> distances(vertex_count, -1);
    distances[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (Edge e : vertices[v].edges) {
            int w = e.to;
            if (w == sink)
                return true;
            if (distances[w] == -1) {
                distances[w] = distances[v] + 1;
                q.push(w);
            }
        }
    }
    return false;
}
