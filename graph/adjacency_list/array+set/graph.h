#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

struct Edge_Info{
    int vertex;
    double weight;

    bool operator==(const Edge_Info &other) const {
        return vertex == other.vertex && weight == other.weight;
    }
};


struct hash_function{
    size_t operator()(const Edge_Info &x) const{
        return std::hash<int>()(x.vertex) ^ std::hash<double>()(x.weight);
    }
};

struct Undirected_Graph{
    std::vector<std::unordered_set<Edge_Info, hash_function>> adj_list;
    std::vector<bool> initialized;
    int edge_count;
};

struct Directed_Graph{
    std::vector<std::unordered_set<Edge_Info, hash_function>> adj_list;
    std::vector<bool> initialized;
};


Undirected_Graph create_undirected_graph(int vertices);
void add_edge(Undirected_Graph &graph, int v1, int v2, double weight);
void add_vertex(Undirected_Graph &graph, int v);
void remove_vertex(Undirected_Graph &graph, int v);
void remove_edge(Undirected_Graph &graph, int v1, int v2);
void print_graph(const Undirected_Graph &g);
int get_node_count(Undirected_Graph &graph);
int get_edge_count(Undirected_Graph &graph);


Directed_Graph  create_directed_graph(int vertices);
void add_vertex(Directed_Graph &graph, int v);
void add_edge(Directed_Graph &graph, int source, int destination, double weight);
void remove_vertex(Directed_Graph &graph, int target);
void remove_edge(Directed_Graph &graph, int v1, char v2);
void print_graph(const Directed_Graph &g);
int get_node_count(Directed_Graph &graph);
int get_edge_count(Directed_Graph &graph);

// Helper
bool in_bounds(Undirected_Graph &g, int index);
bool in_bounds(Directed_Graph &g, int index);
void remove_target(std::unordered_set<Edge_Info, hash_function> &list, int target);

// Traverse
void BFS(Undirected_Graph &g, int start);
void dijkstra(Undirected_Graph g, int start, int dest);