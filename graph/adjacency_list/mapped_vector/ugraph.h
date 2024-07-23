#include <iostream>
#include <unordered_map>
#include <vector>

#ifndef MAPPED_VECTOR_UGRAPH_H
#define MAPPED_VECTOR_UGRAPH_H


class ugraph {
public:
    ugraph * create_graph();
    void add_edge(char v1, char v2, double weight);
    void add_vertex(char v);
    void print_graph();
    int get_node_count();
    int get_edge_count();
private:
    std::unordered_map<char, std::vector<char>> adj_list;
    int edges;
};


#endif //MAPPED_VECTOR_UGRAPH_H
