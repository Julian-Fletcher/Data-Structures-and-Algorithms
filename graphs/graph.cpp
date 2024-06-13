#include "graph.h"

// Returns a graph variable
Graph create_gaph(void){
    Graph graph;
    graph.node_count = new int;
    graph.edge_count = new int;

    *(graph.node_count) = 0;
    *(graph.edge_count) = 0;

    return graph;
}

// Creates an edge between v1 and v2 with the specified weight
void add_edge(const char v1, const char v2 , const double weight){
    
}

// New row created
void add_vertex(const char v){

}

// The vertex row will be deleted
void remove_vertex(const char v){

}

// Two vertices will be found and the edge between them removed
void remove_edge(const char v1, const char v2){

}