#include "graph.h"

using std::unordered_map;
using std::unordered_set;

Undirected_Graph create_undirected_graph(){
    Undirected_Graph g;
    return g;
}

void add_edge(Undirected_Graph &graph, char v1, char v2, double weight){
    // Early return if edge not added
    if(graph.vertices.count(v1) == 0 || graph.vertices.count(v2) == 0){
        return;
    }
    Edge e1 = {.v1 = v1, .v2 = v2};
    Edge e2 = {.v1 = v2, .v2 = v1};

    graph.adj_map.insert(std::make_pair(e1, weight));
    graph.adj_map.insert(std::make_pair(e2, weight));
}

void add_vertex(Undirected_Graph &graph, char v){
    graph.vertices.insert(v);
}

void remove_vertex(Undirected_Graph &graph, char target){
    if(graph.vertices.count(target) == 0){
        return;
    }
    graph.vertices.erase(target);
    // O(E) removal from hashmap where E is the # of edges
    for(auto it = graph.adj_map.begin(); it != graph.adj_map.end();){
        if(it->first.v1 == target || it->first.v2 == target){
            it = graph.adj_map.erase(it);
            continue;
        }
        it++;
    }
}

void remove_edge(Undirected_Graph &graph, char v1, char v2){
    Edge e1 = {.v1 = v1, .v2 = v2};
    Edge e2 = {.v1 = v2, .v2 = v1};
    // Delete edge and its opposite
    graph.adj_map.erase(graph.adj_map.find(e1));     // This should be average case o(1) worst case o(n) with collision
    graph.adj_map.erase(graph.adj_map.find(e2));
}

void list_edges(const Undirected_Graph &g){
    std::cout << "Vertices: " << g.vertices.size() << "\n";
    std::cout << "Edges: " << g.adj_map.size() << "\n";
    for(auto item : g.adj_map){
        std::cout << item.first.v1 << "-" << item.first.v2 << "\t" << "Weight: " << item.second << "\n";
    }
}

unsigned int get_edge_count(const Undirected_Graph &g){
    return g.adj_map.size();
}

unsigned int get_vertex_count(const Undirected_Graph &g){
    return g.adj_map.size();
}

