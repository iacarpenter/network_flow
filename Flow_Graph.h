#ifndef CDS242_FLOW_GRAPH_H
#define CDS242_FLOW_GRAPH_H

#include <vector>

class FlowGraph {
public:
    FlowGraph(std::size_t v, int source, int sink);
    void add_edge(int from, int to, int capacity);
    int max_flow();

private:
    struct Edge {
        int from;
        int to;
        int capacity;
        int remaining_capacity;
        int flow = 0; // flow initialized to 0
        bool is_reverse;

        Edge(int f, int t, int c, bool reverse = false);
    };

    struct Vertex {
        int id;
        std::vector<Edge> edges;

        Vertex(int i);
    };

private:
    bool bfs();

private:
    int source;
    int sink;
    int vertex_count;
    std::vector<Vertex> vertices;
};

#endif // CDS242_FLOW_GRAPH_H