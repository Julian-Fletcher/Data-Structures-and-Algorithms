#include "Graph.h"
#include <queue>
#include <stack>
#include <vector>
#include <limits>
#include <ranges>

Graph::Graph(int v){
    this->size = v;
    this->adj = new int*[v];

    for(int i = 0; i < v; ++i){
        adj[i] = new int[v];
        for(int j = 0; j < v; ++j){
            adj[i][j] = -1;
        }
    }
}

void Graph::add_edge(int src, int dest, int weight){
    if(!(0 <= src < this->size) || !(0 <= dest < this->size)){
        return;
    }

    adj[src][dest] = weight;
    adj[dest][src] = weight;
}

void Graph::BFS(int start){
    std::queue<int> queue;
    std::vector<int> visited(this->size, 0);
    int current_node;
    std::cout << "BFS from: " << start << ": ";
    queue.push(start);

    while(!queue.empty()){
        // Pop node if it has already been visited
        if(visited[queue.front()]){
            queue.pop();
            continue;
        }
        current_node = queue.front();
        queue.pop();
        visited[current_node] = 1;

        for(int i = 0; i < this->size; ++i){
            if(visited[i] || this->adj[current_node][i] == -1) continue;
            queue.push(i);
        }
        std::cout << " -> " << current_node;
    }
    std::cout << std::endl;
}

void Graph::DFS(int start){
    std::stack<int> stack;
    std::vector<int> visited(this->size, 0);
    int current_node;
    std::cout << "DFS from: " << start << ": ";
    stack.push(start);

    while(!stack.empty()){
        // Pop node if it has already been visited
        if(visited[stack.top()]){
            stack.pop();
            continue;
        }
        current_node = stack.top();
        stack.pop();
        visited[current_node] = 1;

        for(int i = 0; i < this->size; ++i){
            if(visited[i] || this->adj[current_node][i] == -1) continue;
            stack.push(i);
        }
        std::cout << " -> " << current_node;
    }
    std::cout << std::endl;
}

// Returns shortest paths to all vertices
void Graph::dijkstra(int start){
    std::vector<bool> visited(this->size, false);
    std::vector<int> distances(this->size, std::numeric_limits<int>::max());
    distances[start] = 0;

    // Loop through every vertex in the graph
    for(int i : std::views::iota(0, this->size)){
        int current_node = -1;
        int min_distance = std::numeric_limits<int>::max();

        for(int j : std::views::iota(0, this->size)){
            if(distances[j] < min_distance && !visited[j]) {
                min_distance = distances[j];
                current_node = j;
            }

        }
        if(current_node == -1) break;   // No more vertices to look at

        for(int edge : std::views::iota(0, this->size)) {
            if (this->adj[current_node][edge] == -1) continue;

            int path_weight = this->adj[current_node][edge] + distances[current_node];
            if (path_weight < distances[edge]) {
                distances[edge] = path_weight;
            }
        }
        visited[current_node] = true;   // Set current node to visited
    }

    for(int i : std::views::iota(0,this->size)){
        std::cout << i << "\t" << distances[i] << "\n";
    }
}

// Returns shortest path to destination
void Graph::dijkstra(int start, int end){
    std::vector<bool> visited(this->size, false);
    std::vector<int> distances(this->size, std::numeric_limits<int>::max());
    std::vector<int> previous(this->size);
    distances[start] = 0;
    int current_node = -1;

    // Loop through every vertex in the graph
    for(int i : std::views::iota(0, this->size)){
        int min_distance = std::numeric_limits<int>::max();

        // Find the next vertex with the lowest weight
        for(int j : std::views::iota(0, this->size)){
            if(current_node == end) break;          // If destination is found, break loop
            if(distances[j] < min_distance && !visited[j]) {
                min_distance = distances[j];
                current_node = j;
            }
        }
        if(current_node == -1) break;   // No more vertices to look at
        if(current_node == end) break;  // Break if current node found

        for(int edge : std::views::iota(0, this->size)) {
            if (this->adj[current_node][edge] == -1) continue;

            int path_weight = this->adj[current_node][edge] + distances[current_node];
            if (path_weight < distances[edge]) {
                distances[edge] = path_weight;
                previous[edge] = current_node;
            }
        }
        visited[current_node] = true;   // Set current node to visited
    }

    std::cout << "Path from " << start << " to " << end << "\n";
    std::stack<int> path;

    while(current_node != start){
        path.push(current_node);
        current_node = previous[current_node];
    }
    path.push(start);
    int x;
    while(!path.empty()){
        x = path.top();
        path.pop();
        std::cout << x << " ";
    }

}


void Graph::print(){
    for(int i = 0; i < this->size; i++){
        std::cout << i << ": ";
        for(int j = 1; j < this->size; j++){
            if(this->adj[i][j] == -1){
                continue;
            }
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}



int main(){
    auto *g = new Graph(15);
    g->add_edge(0,4,3);
    g->add_edge(0,5,12);
    g->add_edge(1,13,14);
    g->add_edge(13,4,6);
    g->add_edge(13,2,11);
    g->add_edge(2,14,7);
    g->add_edge(3,6,9);
    g->add_edge(3,5,18);
    g->add_edge(4,5,1);
    g->add_edge(4,14,15);
    g->add_edge(4,6,4);
    g->add_edge(5,7,22);
    g->add_edge(5,10,3);
    g->add_edge(6,9,6);
    g->add_edge(6,11,1);
    g->add_edge(7,9,8);
    g->add_edge(8,14,2);
    g->add_edge(8,11,20);
    g->add_edge(8,12,12);
    g->add_edge(9,10,4);
    g->add_edge(9,11,19);
    g->add_edge(11,12,6);


    g->print();

    g->BFS(1);
    g->DFS(1);
    g->dijkstra(1);
    g->dijkstra(1, 12);
    delete g;
}