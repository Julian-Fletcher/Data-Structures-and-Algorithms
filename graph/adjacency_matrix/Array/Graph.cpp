#include "Graph.h"
#include <queue>
#include <stack>
#include <vector>
#include <limits>
#include <ranges>
#include <chrono>
#include <random>

#define SIZE 200000

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
    if (src < 0 || src >= this->size || dest < 0 || dest >= this->size) {
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
void Graph::dijkstra_search(int start, int end){

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    dij_array(start, end);

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "Array implementation time: " << time_span.count() << " seconds.\n";

    t1 = std::chrono::high_resolution_clock::now();

    dij_pqueue(start, end);

    t2 = std::chrono::high_resolution_clock::now();

    time_span = duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "Min-heap implementation time: " << time_span.count() << " seconds.\n";
}

void Graph::dij_pqueue(int start, int end){
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> p_queue;
    std::vector<int> distances(this->size, std::numeric_limits<int>::max());
    std::vector<int> previous(this->size);
    std::pair<int, int> current_node;

    p_queue.emplace(0, start);  // Puts a pair into the queue. Emplace instead of push because it constructs in place
    distances[start] = 0;

    while(!p_queue.empty()){
        current_node = p_queue.top();
        if(current_node.second == end){
            break;
        }
        p_queue.pop();
        for(int neighbor : std::views::iota(0, this->size)){
            if(this->adj[current_node.second][neighbor] == -1){
                continue;
            }
            int path_weight = distances[current_node.second] + this->adj[current_node.second][neighbor];
            if(path_weight < distances[neighbor]){
                distances[neighbor] = path_weight;
                p_queue.emplace(distances[neighbor], neighbor);
                previous[neighbor] = current_node.second;
            }
        }
    }


    std::cout << "Path from " << start << " to " << end << "\n";
    std::stack<int> path;

    while(current_node.second != start){
        path.push(current_node.second);
        current_node.second = previous[current_node.second];
    }
    path.push(start);
    int x;
    while(path.size() != 1){
        x = path.top();
        path.pop();
        std::cout << x << " -> ";
    }
    x = path.top();
    path.pop();
    std::cout << x << "\n";
}

void Graph::dij_array(int start, int end){
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
    while(path.size() != 1){
        x = path.top();
        path.pop();
        std::cout << x << " -> ";
    }
    x = path.top();
    path.pop();
    std::cout << x << "\n";
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


double random_num_d(){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}


int random_num_i(){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, SIZE - 1);
    return dis(gen);
}

int main(){
    int weight;

    Graph g(SIZE);

    for(int i : std::views::iota(0, 5)){
        for (int j = 0; j < SIZE; ++j) {
            weight = random_num_i();
            g.add_edge(j, random_num_i(), weight);
        }
    }
//    g.print();
//    g.BFS(random_num_i());
//    g.DFS(random_num_i());
//    g.dijkstra(random_num_i());

    g.dijkstra_search(random_num_i(), random_num_i());

}