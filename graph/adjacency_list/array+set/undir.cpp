#include "graph.h"

Undirected_Graph create_undirected_graph(int vertices){
    Undirected_Graph g;
    g.adj_list.resize(vertices);
    g.initialized.resize(vertices);
    g.edge_count = 0;
    return g;
}

void add_edge(Undirected_Graph &graph, int v1, int v2, double weight){
    // Confirm vertices are within bounds
    if(!in_bounds(graph, v1) || !in_bounds(graph, v2)){
        return;
    }

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
    graph.adj_list[v] = std::unordered_set<Edge_Info, hash_function>();
}

void remove_vertex(Undirected_Graph &graph, int v){
    // Confirm vertices are within bounds
    if(!in_bounds(graph, v)){
        return;
    }

    graph.initialized[v] = false;
    graph.adj_list[v].clear();

    for(auto list = 0; list < graph.adj_list.size(); list++){
        for(auto &edge : graph.adj_list[list]){
            if(edge.vertex == v){
                graph.adj_list[list].erase(edge);
                break;
            }
        }
    }

}

void remove_edge(Undirected_Graph &graph, int v1, int v2){
    // Confirm vertices are within bounds
    if(!in_bounds(graph, v1)|| !in_bounds(graph, v2)){
        return;
    }

    remove_target(graph.adj_list[v1], v2);
    remove_target(graph.adj_list[v2], v1);
}

void print_graph(const Undirected_Graph &g){
    for(auto i = 0; i < g.adj_list.size(); i++){
        std::cout << i << ": ";
        for(auto &edge : g.adj_list[i]){
            std::cout << edge.vertex << "[" << edge.weight << "], ";
        }
        std::cout << "\n";
    }
}

int get_node_count(Undirected_Graph &graph){
    return graph.adj_list.size();
}

int get_edge_count(Undirected_Graph &graph){
    return graph.edge_count;
}

bool in_bounds(Undirected_Graph &g, int index){
    // Confirm vertices are within bounds
    if(index > g.adj_list.capacity()){
        return false;
    }
    return true;
}

void remove_target(std::unordered_set<Edge_Info, hash_function> &list, int target){
    for(auto edge = list.begin(); edge != list.end();){
        if(edge->vertex == target){
            edge = list.erase(edge);
            return;
        }
        edge++;
    }
}

