#include "graph.h"

using std::vector;
using std::swap;

Directed_Graph  create_directed_graph(){
    Directed_Graph graph;
    graph.node_count = 0;
    graph.edge_count = 0;
    return graph;
}

// UPDATED
void add_edge(Directed_Graph &graph, char start, char end, double weight) {
    size_t start_location = locate_vertex(graph.adj_list, start);
    size_t end_location = locate_vertex(graph.adj_list, end);

    if(start_location == -1 || end_location == -1){
        return;
    }

    Edge e = {.node = end, .weight = weight};

    graph.adj_list[start_location].push_back(e);
    graph.edge_count++;
}

// UPDATED
void add_vertex(Directed_Graph &graph, char v){
    Edge e = {.node = v};
    if(graph.adj_list.empty()){
        graph.adj_list.push_back(vector<Edge>{e});
        return;
    }

    for(auto it : graph.adj_list){
        if(it[0].node == v){
            return;
        }
    }

    graph.adj_list.push_back(vector<Edge>{e});
    graph.node_count++;

}

void remove_vertex(Directed_Graph &graph, char v){
    size_t v_location = locate_vertex(graph.adj_list, v);
    if(v_location == -1){
        return;
    }

    std::swap(graph.adj_list[v_location], graph.adj_list.back());
    graph.adj_list.pop_back();
    graph.node_count--;
    for(auto &row : graph.adj_list){
        delete_edge(row, v);
    }
}

void remove_edge(Directed_Graph &graph, char src, char dest){
    size_t src_location = locate_vertex(graph.adj_list, src);

    if(src_location == -1){
        return;
    }

    size_t edge_location = locate_vertex(graph.adj_list[src_location], dest);
    if(edge_location == -1){
        return;
    }
    std::swap(graph.adj_list[src_location][edge_location], graph.adj_list[src_location].back());
    graph.adj_list[src_location].pop_back();
    graph.edge_count--;
}

void print_graph(const Directed_Graph &g){
    std::cout << "Graph Node Count: " << g.node_count << "\nGraph Edge Count: " << g.edge_count << "\n";
    for(auto &row : g.adj_list){
        std::cout << row[0].node << ": ";
        for(auto &col : row){
            if(col.node == row[0].node){
                continue;
            }
            std::cout << col.node << "{" << col.weight << "} ";
        }
        std::cout << "\n";
    }
}

int get_node_count(Directed_Graph &graph){
    return graph.node_count;
}
int get_edge_count(Directed_Graph &graph){
    return graph.edge_count;
}