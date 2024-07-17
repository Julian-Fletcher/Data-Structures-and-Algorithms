#include "graph.h"
#include <queue>
#include <unordered_set>

void BFS(Undirected_Graph &g, int start){
    std::queue<int> v_queue;
    std::unordered_set<int> visited;

    std::cout << "BFS starting at " << start << ": ";

    int current_node;
    v_queue.push(start);

    while(!v_queue.empty()){
        // Skip current node if it's been visited
        if(visited.count(v_queue.front()) != 0){
            v_queue.pop();
            continue;
        }
        current_node = v_queue.front();
        v_queue.pop();
        visited.insert(current_node);

        // Push all adjacent nodes into the queue
        for(auto edge : g.adj_list[current_node]){
            v_queue.push(edge.vertex);
        }

        std::cout << current_node << ", ";
    }
    std::cout << std::endl;
}

void dijkstra(Undirected_Graph &g, int start, int dest){

}