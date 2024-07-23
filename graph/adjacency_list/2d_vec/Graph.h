#include <iostream>
#include <vector>
#include <ranges>
#include <limits>


#ifndef INC_2D_VEC_GRAPH_H
#define INC_2D_VEC_GRAPH_H

struct Edge{
    int v;
    int weight;
};

class Graph {
public:
    explicit Graph(int v);
    void add_edge(int src, int dest, int weight);
    void print();
    void DFS(int src);
    void BFS(int src);
    void dijkstra(int start);
    void dijkstra(int start, int dest);
private:
    std::vector<Edge> *adj;
    int size;
};


#endif //INC_2D_VEC_GRAPH_H
