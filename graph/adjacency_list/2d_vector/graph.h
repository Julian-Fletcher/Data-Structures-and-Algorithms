#include <iostream>
#include <vector>
#include <algorithm>

struct Edge{
    char node;
    double weight;
};

struct Undirected_Graph{
    std::vector<std::vector<Edge>> adj_list;
    int node_count;
    int edge_count;
};

struct Directed_Graph{
    std::vector<std::vector<Edge>> adj_list;
    int node_count;
    int edge_count;
};


Undirected_Graph create_undirected_graph();                                     // Returns undirected graph
void add_edge(Undirected_Graph &graph, char v1, char v2, double weight);        // Creates an edge between v1 and v2 with the specified weight
void add_vertex(Undirected_Graph &graph, char v);                               // New row created
void remove_vertex(Undirected_Graph &graph, char v);                            // The vertex row will be deleted
void remove_edge(Undirected_Graph &graph, char v1, char v2);                    // Two vertices will be found and the edge between them removed
void print_graph(const Undirected_Graph &g);
int get_node_count(Undirected_Graph &graph);
int get_edge_count(Undirected_Graph &graph);


Directed_Graph  create_directed_graph();                                        // Return directed graph
void add_vertex(Directed_Graph &graph, char v);                                 // New row created
void add_edge(Directed_Graph &graph, char source, char destination, double weight);      // Function overload for directed graphs
void remove_vertex(Directed_Graph &graph, char target);                              // The vertex row will be deleted
void remove_edge(Directed_Graph &graph, char v1, char v2);                      // Function overload for directed graphs
void print_graph(const Directed_Graph &g);
int get_node_count(Directed_Graph &graph);
int get_edge_count(Directed_Graph &graph);



// Helper functions
size_t locate_vertex(const std::vector<std::vector<Edge>> &adj_list, char target);
size_t locate_vertex(std::vector<Edge> &col, char target);
bool delete_edge(std::vector<Edge> &row, char target);


// Graph Traversal
void BFS(Undirected_Graph &g, char start);
void BFS(Directed_Graph &g, char start);
void DFS(Undirected_Graph &g, char start);
void DFS(Directed_Graph &g, char start);