#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>

struct Edge{
    char v1, v2;

    // needed for hash
    bool operator==(const Edge &other) const {
        return v1 == other.v1 && v2 == other.v2;
    }
};

// Hash function
struct EdgeHash{
    std::size_t operator()(const Edge &key) const {
        return std::hash<char>()(key.v1) ^ std::hash<char>()(key.v2);
    }
};

struct Undirected_Graph{
    std::unordered_map<Edge, double, EdgeHash> adj_map;
    std::unordered_set<char> vertices;
};

struct Directed_Graph{
    std::unordered_map<Edge, double, EdgeHash> adj_map;
    int vertex_count;
    std::unordered_set<char> vertices;
};

Undirected_Graph create_undirected_graph();
void add_edge(Undirected_Graph &graph, char v1, char v2, double weight);
void add_vertex(Undirected_Graph &graph, char v);
void remove_vertex(Undirected_Graph &graph, char target);
void remove_edge(Undirected_Graph &graph, char v1, char v2);
void list_edges(const Undirected_Graph &g);
unsigned int get_edge_count(const Undirected_Graph &g);
unsigned int get_vertex_count(const Undirected_Graph &g);

Directed_Graph create_directed_graph();
void add_edge(Directed_Graph &graph, char source, char destination, double weight);
void add_vertex(Directed_Graph &graph, char v);
void remove_vertex(Directed_Graph &graph, char target);
void remove_edge(Directed_Graph &graph, char source, char destination);
void list_edges(const Directed_Graph &g);
unsigned int get_edge_count(const Directed_Graph &g);
unsigned int get_vertex_count(const Directed_Graph &g);