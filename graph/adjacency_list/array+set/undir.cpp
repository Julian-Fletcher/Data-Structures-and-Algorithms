#include "graph.h"

Undirected_Graph create_undirected_graph(int vertices){
    Undirected_Graph g;
    g.adj_list.reserve(vertices);
    g.initialized.reserve(vertices);
    return g;
}

void add_edge(Undirected_Graph &graph, int v1, int v2, double weight){
    // Confirm vertices are within bounds
    if()

    // Confirm vertices have been added
    if(!graph.initialized[v1] || !graph.initialized[v2]){
        return;
    }
    Edge_Info edge1 = {.vertex = v2, .weight = weight};
    Edge_Info edge2 = {.vertex = v1, .weight = weight};
    graph.adj_list[v1].insert(edge1);
    graph.adj_list[v2].insert(edge2);
}


void add_vertex(Undirected_Graph &graph, int v){
    if(graph.initialized[v]){
        return;
    }
    graph.initialized[v] = true;
    graph.adj_list[v] = std::unordered_set<Edge_Info, hash_function>;
}

void remove_vertex(Undirected_Graph &graph, int v){
    // Confirm vertices are within bounds
    if(v > graph.adj_list.capacity()){
        return;
    }
    graph.initialized[v] = false;
    graph.adj_list[v].clear();

    for(auto &list : graph.adj_list){
        for(auto &edge : list){
            if(edge.vertex == v){
                list.erase(edge);
            }
        }
    }
}

void remove_edge(Undirected_Graph &graph, int v1, int v2){
    // Confirm vertices are within bounds
    if(v1 > graph.adj_list.capacity() || v2 > graph.adj_list.capacity()){
        return;
    }
}

void print_graph(const Undirected_Graph &g);
int get_node_count(Undirected_Graph &graph);
int get_edge_count(Undirected_Graph &graph);

bool in_bounds(Undirected_Graph &g, int index){
    // Confirm vertices are within bounds
    if(index > g.adj_list.capacity()){
        return false;
    }
    return true;
}