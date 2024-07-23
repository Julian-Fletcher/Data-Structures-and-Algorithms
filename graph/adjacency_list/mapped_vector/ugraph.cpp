#include "ugraph.h"

ugraph* ugraph::create_graph() {
    ugraph *g = new ugrpah;
    return g;
}

void ugraph::add_edge(char v1, char v2, double weight) {

}

int ugraph::get_edge_count() {
    return this->edges;
}

int ugraph::get_node_count() {
    return this->adj_list.size();
}