#include "graph.h"

using std::vector;
using std::swap;

Undirected_Graph create_undirected_graph(){
    Undirected_Graph graph;
    graph.node_count = 0;
    graph.edge_count = 0;
    return graph;
}

// UPDATED
void add_edge(Undirected_Graph &graph, char v1, char v2, double weight) {
    size_t v1_location = locate_vertex(graph.adj_list, v1);
    size_t v2_location = locate_vertex(graph.adj_list, v2);

    if(v1_location == -1 || v2_location == -1){
        return;
    }

    Edge e1 = {.node = v2, .weight = weight};
    Edge e2 = {.node = v1, .weight = weight};

    graph.adj_list[v1_location].push_back(e1);
    graph.adj_list[v2_location].push_back(e2);
    graph.edge_count++;
}
// UPDATED
void add_vertex(Undirected_Graph &graph, const char v){
    Edge e {.node = v};     // Need to find default unit value for weight later
    if(graph.adj_list.empty()){
        graph.adj_list.push_back(vector<Edge>{e});
        graph.node_count++;
        return;
    }

    for(auto it : graph.adj_list){
        if(it[0].node == e.node){               // Check if nodes are the same
            return;
        }
    }

    graph.adj_list.push_back(vector<Edge>{e});
    graph.node_count++;
}

// UPDATED
void remove_vertex(Undirected_Graph &graph, const char v){
    size_t v_location = locate_vertex(graph.adj_list, v);
    bool edge_removed{false};
    if(v_location == -1){
        return;
    }

    std::swap(graph.adj_list[v_location], graph.adj_list.back());
    graph.adj_list.pop_back();
    graph.node_count--;
    for(auto &row : graph.adj_list){
        edge_removed = delete_edge(row, v);
        if(edge_removed){
            graph.edge_count--;
        }
    }

}

// UPDATED
void remove_edge(Undirected_Graph &graph, const char v1, const char v2){
    size_t v1_location = locate_vertex(graph.adj_list, v1);
    size_t v2_location = locate_vertex(graph.adj_list, v2);

    if(v1_location == -1 || v2_location == -1){
        return;
    }

    // Locate v2 in v1 vector
    size_t e1_location = locate_vertex(graph.adj_list[v1_location], v2);
    if(e1_location == -1){
        return;
    }
    std::swap(graph.adj_list[v1_location][e1_location], graph.adj_list[v1_location].back());
    graph.adj_list[v1_location].pop_back();

    // Locate v1 in v2 vector
    size_t e2_location = locate_vertex(graph.adj_list[v2_location], v1);
    std::swap(graph.adj_list[v2_location][e2_location], graph.adj_list[v2_location].back());
    graph.adj_list[v2_location].pop_back();

    graph.edge_count--;
}
// UPDATED
void print_graph(const Undirected_Graph &g){
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

int get_node_count(Undirected_Graph &graph){
    return graph.node_count;
}
int get_edge_count(Undirected_Graph &graph){
    return graph.edge_count;
}



/* Helper Functions */
//UPDATED
size_t locate_vertex(const std::vector<std::vector<Edge>> &adj_list, char target){
    for(size_t row{0}; row < adj_list.size(); row++){
        if(adj_list[row][0].node == target){
            return row;
        }
    }
    return -1;
}
// UPDATED
size_t locate_vertex(vector<Edge> &col, const char key){
    for(size_t i{0}; i < col.size(); i++){
        if(col[i].node == key){
            return i;
        }
    }
    return -1;
}
// UPDATED
bool delete_edge(vector<Edge> &row, const char key){
    for(size_t i{0}; i < row.size(); i++){
        if(row[i].node == key){
            std::swap(row[i], row.back());
            row.pop_back();

            return true;
        }
    }
    return false;
}