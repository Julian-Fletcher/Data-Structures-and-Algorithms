#include <iostream>
#include <vector>

typedef struct graph{
    std::vector<std::vector<int>> adj_matrix;
    int *node_count;
    int *edge_count;

}Graph;


Graph create_gaph(void);                                                    // Returns a graph variable
void add_edge(Graph graph ,const char v1, const char v2 , const double weight);          // Creates an edge between v1 and v2 with the specified weight
void add_vertex(Graph graph, const char v);                                              // New row created
void remove_vertex(Graph graph, const char v);                                           // The vertex row will be deleted
void remove_edge(Graph graph, const char v1, const char v2);                             // Two vertices will be found and the edge between them removed