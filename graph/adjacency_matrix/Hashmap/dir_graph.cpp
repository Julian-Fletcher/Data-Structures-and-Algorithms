#include "graph.h"

using std::unordered_set;
using std::unordered_map;

Directed_Graph create_directed_graph(){
    Directed_Graph g;
    return g;
}

void add_edge(Directed_Graph &graph, char source, char destination, double weight){
    // Early return if edge not added
    if(graph.vertices.count(source) == 0 || graph.vertices.count(destination) == 0){
        return;
    }

    Edge e = {.v1 = source, .v2 = destination};
    graph.adj_map.insert(std::make_pair(e, weight));
}

void add_vertex(Directed_Graph &graph, char v){
    graph.vertices.insert(v);
}

void remove_vertex(Directed_Graph &graph, char target){
    if(graph.vertices.count(target) == 0){
        return;
    }
    graph.vertices.erase(target);

    for(auto it = graph.adj_map.begin(); it != graph.adj_map.end();){
        if(it->first.v1 == target || it->first.v2 == target){
            it = graph.adj_map.erase(it);
            continue;
        }
        it++;
    }
}

void remove_edge(Directed_Graph &graph, char source, char destination){
    Edge e = {.v1 = source, .v2 = destination};
    graph.adj_map.erase(graph.adj_map.find(e));
}

void list_edges(const Directed_Graph &g){
    std::cout << "Vertices: " << g.vertices.size() << "\n";
    std::cout << "Edges: " << g.adj_map.size() << "\n";
    for(auto item : g.adj_map){
        std::cout << item.first.v1 << "-" << item.first.v2 << "\t" << "Weight: " << item.second << "\n";
    }
}

unsigned int get_edge_count(const Directed_Graph &g){
    return g.adj_map.size();
}

unsigned int get_vertex_count(const Directed_Graph &g){
    return g.adj_map.size();
}