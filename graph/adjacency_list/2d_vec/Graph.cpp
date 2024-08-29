#include "Graph.h"
#include <queue>
#include <stack>
#include <utility>
#include <chrono>
#include <random>

using std::vector;

#define SIZE 100000

Graph::Graph(int v) {
    this->size = v;
    this->adj = new std::vector<Edge>[v];
}

void Graph::add_edge(int src, int dest, int weight) {
    Edge e = {.vertex = dest, .weight = weight};
    this->adj[src].push_back(e);
    e.vertex = src;
    this->adj[dest].push_back(e);
}

void Graph::print() {
    for(int i : std::views::iota(0,this->size)){
        std::cout << i << ": ";
        for(Edge &e : this->adj[i]){
            std::cout << e.vertex << "(W: " << e.weight << ") ";
        }
        std::cout << "\n";
    }
}

void Graph::DFS(int src) {
    std::stack<int>stack;
    std::vector<bool>visited(this->size, false);
    int current = -1;
    stack.push(src);
    std::cout << "DFS from node: " << src << "\n";
    while(!stack.empty()){
        if(visited[stack.top()]){
            stack.pop();
            continue;
        }
        current = stack.top();
        stack.pop();
        visited[current] = true;
        std::cout << current << " ";
        for(Edge &e : this->adj[current]){
            if(visited[e.vertex]){
               continue;
            }
            stack.push(e.vertex);
        }
    }
}

void Graph::BFS(int src) {
    std::queue<int>queue;
    std::vector<bool>visited(this->size, false);
    int current = -1;
    queue.push(src);
    std::cout << "BFS from node: " << src << "\n";
    while(!queue.empty()){
        if(visited[queue.front()]){
            queue.pop();
            continue;
        }
        current = queue.front();
        queue.pop();
        visited[current] = true;
        std::cout << current << " ";
        for(Edge &e : this->adj[current]){
            if(visited[e.vertex]){
                continue;
            }
            queue.push(e.vertex);
        }

    }
}

void Graph::dijkstra(int start) {
    std::vector<bool>visited(this->size, false);
    std::vector<int>distances(this->size, std::numeric_limits<int>::max());

    int current_vertex = -1;
    distances[start] = 0;
    int smallest_distance;

    for(int vertex : std::views::iota(0, this->size)){
        smallest_distance = std::numeric_limits<int>::max();

        for(int candidate : std::views::iota(0, this->size)){
            if(distances[candidate] < smallest_distance && !visited[candidate]){
                smallest_distance = distances[candidate];
                current_vertex = candidate;
            }
        }

        for(Edge neighbor : this->adj[current_vertex]){
            int new_distance = distances[current_vertex] + neighbor.weight;
            if(new_distance < distances[neighbor.vertex]){
                distances[neighbor.vertex] = new_distance;
            }
        }
        visited[current_vertex] = true;
    }

    std::cout << "Shortest Paths to All Vertices\n";
    for(int i : std::views::iota(0,this->size)){
        std::cout << i << "\t" << distances[i] << "\n";
    }
}

void Graph::dijkstra_search(int start, int end) {
    std::cout << "Performance on graph of size: " << SIZE << "\n";
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    dij_array(start, end);

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span = duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "Array implementation time: " << time_span.count() << " seconds.\n";

    t1 = std::chrono::high_resolution_clock::now();

    std::cout << std::endl;
    dij_pqueue(start, end);

    t2 = std::chrono::high_resolution_clock::now();

    time_span = duration_cast<std::chrono::duration<double>>(t2 - t1);

    std::cout << "Min-heap implementation time: " << time_span.count() << " seconds.\n";
}

void Graph::dij_pqueue(int start, int end) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    vector<int> distances(this->size, std::numeric_limits<int>::max());
    vector<int> previous(this->size);
    std::stack<int> path;
    int final_weight = 0;

    std::pair<int, int> current_node;

    pq.emplace(0, start);
    distances[start] = 0;


    while (!pq.empty()) {
        current_node = pq.top();
        pq.pop();

        if(current_node.second == end){
            break;
        }

        for (Edge edge: this->adj[current_node.second]) {
            int path_weight = distances[current_node.second] + edge.weight;
            if (path_weight < distances[edge.vertex]) {
                distances[edge.vertex] = path_weight;
                pq.emplace(distances[edge.vertex], edge.vertex);
                previous[edge.vertex] = current_node.second;
            }
        }
    }

//    std::cout << "Path from " << start << " to " << end << " from pqueue\n";
//
//    while (current_node.second != start) {
//        path.push(current_node.second);
//        current_node.second = previous[current_node.second];
//    }
//    path.push(start);
//    int x;
//    while (path.size() != 1) {
//        x = path.top();
//        path.pop();
//        std::cout << x << " -> ";
//    }
//    x = path.top();
//    path.pop();
//    std::cout << x << "\n";

}


void Graph::dij_array(int start, int end) {
    vector<bool>visited(this->size, false);
    vector<int>distances(this->size, std::numeric_limits<int>::max());
    vector<int>previous(this->size);
    std::stack<int>path;

    int current_node = -1;
    distances[start] = 0;
    int smallest_distance;

    for(int vertex : std::views::iota(0, this->size)){
        smallest_distance = std::numeric_limits<int>::max();

        for(int candidate : std::views::iota(0, this->size)){
            if(current_node == end) break;
            if(distances[candidate] < smallest_distance && !visited[candidate]){
                smallest_distance = distances[candidate];
                current_node = candidate;
            }
        }

        if(current_node == end) break;

        for(Edge neighbor : this->adj[current_node]){
            int new_distance = distances[current_node] + neighbor.weight;
            if(new_distance < distances[neighbor.vertex]){
                distances[neighbor.vertex] = new_distance;
                previous[neighbor.vertex] = current_node;
            }
        }
        visited[current_node] = true;
    }

//    std::cout << "Path from " << start << " to " << end << " from array:\n";
//
//    while(current_node != start){
//        path.push(current_node);
//        current_node = previous[current_node];
//    }
//    path.push(start);
//    int x;
//    while(path.size() != 1){
//        x = path.top();
//        path.pop();
//        std::cout << x << " -> ";
//    }
//    x = path.top();
//    path.pop();
//    std::cout << x << "\n";
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


int main() {
    int weight;
    Graph g(SIZE);

    for(int i : std::views::iota(0, 5)){
        for (int j = 0; j < SIZE; ++j) {
            weight = random_num_i();
            g.add_edge(j, random_num_i(), weight);
        }
    }

//    g.print();
//    g.DFS(s);
//    g.BFS(s);
//    g.dijkstra(s);

g.dijkstra_search(random_num_i(), random_num_i());
    return 0;
}