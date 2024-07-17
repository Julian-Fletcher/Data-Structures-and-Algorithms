#include "graph.h"


int main(){
    Undirected_Graph g = create_undirected_graph(10);

    for(int i = 0; i < 10; i++){
        add_vertex(g, i);
    }

    add_edge(g, 1, 2, 0.2);
    add_edge(g, 1, 3, 0.5);
    add_edge(g, 2, 3, 1.2);
    add_edge(g, 3, 4, 0.02);
    add_edge(g, 4, 5, 0.0);
    add_edge(g, 1, 6, 1.2);
    add_edge(g, 6, 7, 2.3);
    add_edge(g, 5, 8, 4.4);
    add_edge(g, 4, 8, 2.1);
    add_edge(g, 4, 9, 0.23);
    add_edge(g, 8, 9, 0.04);
    add_edge(g, 0, 9, 0.003);
    add_edge(g, 5, 00, 1.5);

    print_graph(g);

    //remove_vertex(g, 2);
    std::cout << "\n\n";
    remove_edge(g, 1, 3);

    print_graph(g);

    BFS(g, 2);

    dijkstra(g, 1, 9);

}