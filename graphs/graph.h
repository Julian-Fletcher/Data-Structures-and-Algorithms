#include <iostream>
#include <vector>

typedef struct graph{
    std::vector<std::vector<int>> adj_matrix;
    int *node_count;
    int *edge_count;

    // Function pointers 
    Graph (*create_gaph)(void);                                             // Function pointer to create
    void (*add_edge)(const char, const char, const double);                 // Function pointer to add edge
    void (*add_vertex)(const char);                                         // Function pointer to add vertex
    void (*remove_vertex)(const char);                                      // Function pointer to remove vertex
    void (*remove_edge)(const char, const char);                            // Function pointer to remove edge

}Graph;


Graph create_gaph(void);                                                    // Returns a graph variable
void add_edge(const char v1, const char v2 , const double weight);          // Creates an edge between v1 and v2 with the specified weight
void add_vertex(const char v);                                              // New row created
void remove_vertex(const char v);                                           // The vertex row will be deleted
void remove_edge(const char v1, const char v2);                             // Two vertices will be found and the edge between them removed