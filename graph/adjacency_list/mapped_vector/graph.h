#include <iostream>
#include <unordered_map>
#include <vector>


struct Undirected_Graph{
    std::unordered_map<char, std::vector<char>> adj_list;
};

struct Directed_Graph{
    std::unordered_map<char, std::vector<char>> adj_list;
};


Undirected_Graph create_undirected_graph();
void add_edge(Undirected_Graph &graph, char v1, char v2, double weight);
void add_vertex(Undirected_Graph &graph, char v);
void remove_vertex(Undirected_Graph &graph, char v);
void remove_edge(Undirected_Graph &graph, char v1, char v2);
void print_graph(const Undirected_Graph &g);
int get_node_count(Undirected_Graph &graph);
int get_edge_count(Undirected_Graph &graph);


Directed_Graph  create_directed_graph();
void add_vertex(Directed_Graph &graph, char v);
void add_edge(Directed_Graph &graph, char source, char destination, double weight);
void remove_vertex(Directed_Graph &graph, char target);
void remove_edge(Directed_Graph &graph, char v1, char v2);
void print_graph(const Directed_Graph &g);
int get_node_count(Directed_Graph &graph);
int get_edge_count(Directed_Graph &graph);