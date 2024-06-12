#include <iostream>
#include <vector>

typedef struct node{
    char value;
    bool visited;
}Node;

typedef struct graph{
    std::vector<std::vector<char>> adj_list;        // Adjacency list

}Graph;
