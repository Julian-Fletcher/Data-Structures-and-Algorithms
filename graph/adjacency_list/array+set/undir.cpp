#include "graph.h"

Undirected_Graph create_undirected_graph(int vertices){
    Undirected_Graph g;
    g.adj_list.reserve(vertices);
    return g;
}

void add_edge(Undirected_Graph &graph, int v1, int v2, double weight){
        
}

void add_vertex(Undirected_Graph &graph, int v);
void remove_vertex(Undirected_Graph &graph, int v);
void remove_edge(Undirected_Graph &graph, int v1, int v2);
void print_graph(const Undirected_Graph &g);
int get_node_count(Undirected_Graph &graph);
int get_edge_count(Undirected_Graph &graph);