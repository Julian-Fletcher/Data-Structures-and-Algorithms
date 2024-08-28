#ifndef ARRAY_GRAPH_H
#define ARRAY_GRAPH_H
#include <iostream>
#include <ranges>

class Graph {
    int size;
    int **adj;

public:
    explicit Graph(int v);
    void add_edge(int src, int dest, int weight);
    void BFS(int start);
    void DFS(int start);
    void dijkstra(int start);
    void dijkstra_search(int start, int end);
    void dij_array(int start, int end);
    void dij_pqueue(int start, int end);
    void print();
};


#endif //ARRAY_GRAPH_H
