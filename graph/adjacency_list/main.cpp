#include "graph.h"
#include <random>

using std::cout;

void test_undirected(){
    Undirected_Graph g = create_undirected_graph();
    int v_num{6};

    // Fill graph with vertices
    for(char i{'A'}; i < static_cast<char>('A' + v_num); i++){
        add_vertex(g, i);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);



    for(int i{0}; i < v_num; i++){
        for(int j{0}; j < v_num; j++){
            if(dis(gen) < 0.2){
                add_edge(g, static_cast<char>('A' + i), static_cast<char>('A' + j), dis(gen));
            }
        }
    }

    add_edge(g, 'E', 'F', 0.5);

    
    cout << "****PRINTING ORIGINAL GRAPH**** \n";
    print_graph(g);

    // Modifications
    remove_vertex(g, 'B');
    cout << "****GRAPH AFTER REMOVING VERTEX 'B'**** \n";
    print_graph(g);
    remove_edge(g, 'E', 'F');

    cout << "****GRAPH AFTER REMOVING E-F EDGE**** \n";
    print_graph(g);
}

void test_directed(){
    Directed_Graph g = create_directed_graph();

    int v_num{6};

    // Fill graph with vertices
    for(char i{'A'}; i < static_cast<char>('A' + v_num); i++){
        add_vertex(g, i);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    for(int i{0}; i < v_num; i++){
        for(int j{0}; j < v_num; j++){
            if(dis(gen) < 0.2 && i != j){
                add_edge(g, static_cast<char>('A' + i), static_cast<char>('A' + j), dis(gen));
            }
        }
    }

    cout << "*** PRINTING INITIAL GRAPH *** \n";
    print_graph(g);

    remove_vertex(g, 'D');
    remove_edge(g, 'E', 'G');

    cout << "*** PRINTING GRAPH AFTER MODIFICATION ***\n";
    print_graph(g);

}

int main(){
    cout << "*** TESTING UNDIRECTED GRAPH ***\n";
    test_undirected();
    cout << "\n\n\n *** TESTING DIRECTED GRAPH ***\n";
    test_directed();
}