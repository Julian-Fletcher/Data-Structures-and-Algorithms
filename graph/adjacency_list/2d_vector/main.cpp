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

    BFS(g, 'C');

//    // Modifications
//    remove_vertex(g, 'B');
//    cout << "****GRAPH AFTER REMOVING VERTEX 'B'**** \n";
//    print_graph(g);
//    remove_edge(g, 'E', 'F');
//
//    cout << "****GRAPH AFTER REMOVING E-F EDGE**** \n";
//    print_graph(g);
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

//    BFS(g, 'C');
}

void test_print_undirected(){
    Undirected_Graph g = create_undirected_graph();
    //Directed_Graph g = create_directed_graph();

    add_vertex(g, 'A');
    add_vertex(g, 'B');
    add_vertex(g, 'C');
    add_vertex(g, 'D');
    add_vertex(g, 'E');
    add_vertex(g, 'F');
    add_vertex(g, 'G');
    add_vertex(g, 'H');

    add_edge(g, 'A', 'D', 0.5);
    add_edge(g, 'A', 'E', 0.5);
    add_edge(g, 'A', 'B', 0.5);
    add_edge(g, 'A', 'C', 0.5);
    add_edge(g, 'A', 'G', 0.5);
    add_edge(g, 'A', 'H', 0.5);

    add_edge(g, 'B', 'D', 0.5);
    add_edge(g, 'B', 'F', 0.5);
    add_edge(g, 'B', 'G', 0.5);
    add_edge(g, 'B', 'H', 0.5);
    add_edge(g, 'B', 'C', 0.5);

    add_edge(g, 'E', 'F', 0.5);

    add_edge(g, 'F', 'G', 0.5);

    add_edge(g, 'G', 'C', 0.5);

    add_edge(g, 'C', 'H', 0.5);

//    add_vertex(g, 'A');
//    add_vertex(g, 'B');
//    add_vertex(g, 'C');
//    add_vertex(g, 'D');
//    add_vertex(g, 'E');
//
//    add_edge(g, 'A', 'B', 0.5);
//    add_edge(g, 'A', 'C', 0.7);
//    add_edge(g, 'B', 'D', 0.7);
//    add_edge(g, 'C', 'D', 0.7);
//    add_edge(g, 'C', 'E', 0.7);

    print_graph(g);
    std::cout << "\n\n";
    BFS(g, 'A');
    DFS(g, 'A');
}

void test_print_directed(){
    Undirected_Graph g;
    //Directed_Graph g;

//    add_vertex(g, 'A');
//    add_vertex(g, 'B');
//    add_vertex(g, 'C');
//    add_vertex(g, 'D');
//    add_vertex(g, 'E');
//    add_vertex(g, 'F');
//    add_vertex(g, 'G');
//    add_vertex(g, 'H');
//
//    add_edge(g, 'A', 'D', 0.5);
//    add_edge(g, 'A', 'E', 0.5);
//    add_edge(g, 'A', 'B', 0.5);
//    add_edge(g, 'A', 'C', 0.5);
//    add_edge(g, 'A', 'G', 0.5);
//    add_edge(g, 'A', 'H', 0.5);
//
//    add_edge(g, 'B', 'D', 0.5);
//    add_edge(g, 'B', 'F', 0.5);
//    add_edge(g, 'B', 'G', 0.5);
//    add_edge(g, 'B', 'H', 0.5);
//    add_edge(g, 'B', 'C', 0.5);
//
//    add_edge(g, 'E', 'F', 0.5);
//
//    add_edge(g, 'F', 'G', 0.5);
//
//    add_edge(g, 'G', 'C', 0.5);
//
//    add_edge(g, 'C', 'H', 0.5);

    add_vertex(g, 'A');
    add_vertex(g, 'B');
    add_vertex(g, 'C');
    add_vertex(g, 'D');
    add_vertex(g, 'E');
    add_vertex(g, 'F');
    add_vertex(g, 'G');
    add_vertex(g, 'H');
    add_vertex(g, 'I');
    add_vertex(g, 'J');
    add_vertex(g, 'K');
    add_vertex(g, 'L');


    add_edge(g, 'A', 'B', 0.56);
    add_edge(g, 'A', 'C', 0.78);
    add_edge(g, 'B', 'D', 0.04);
    add_edge(g, 'D', 'C', 0.99);
    add_edge(g, 'C', 'E', 0.78);
    add_edge(g, 'E', 'F', 0.07);
    add_edge(g, 'E', 'G', 0.17);
    add_edge(g, 'G', 'H', 0.68);
    add_edge(g, 'D', 'I', 0.54);
    add_edge(g, 'I', 'J', 0.71);
    add_edge(g, 'J', 'K', 0.21);
    add_edge(g, 'J', 'L', 0.35);

    print_graph(g);
    std::cout << "\n\n";
    BFS(g, 'A');
    DFS(g, 'A');
}

int main(){
    cout << "*** TESTING UNDIRECTED GRAPH ***\n";
//    test_undirected();
//    cout << "\n\n\n *** TESTING DIRECTED GRAPH ***\n";
//    test_directed();

    test_print_undirected();
    //test_print_directed();
}