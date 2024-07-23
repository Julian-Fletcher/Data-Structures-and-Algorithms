#include "Graph.h"

#include <cstdlib>
#include <ctime>
#include <queue>
#include <stack>

Graph::Graph(int v) {
    this->size = v;
    this->adj = new std::vector<Edge>[v];
}

void Graph::add_edge(int src, int dest, int weight) {
    Edge e = {.v = dest, .weight = weight};
    this->adj[src].push_back(e);
    e.v = src;
    this->adj[dest].push_back(e);
}

void Graph::print() {
    for(int i : std::views::iota(0,this->size)){
        std::cout << i << ": ";
        for(Edge &e : this->adj[i]){
            std::cout << e.v << "(W: " << e.weight << ") ";
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
            if(visited[e.v]){
               continue;
            }
            stack.push(e.v);
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
            if(visited[e.v]){
                continue;
            }
            queue.push(e.v);
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
            if(new_distance < distances[neighbor.v]){
                distances[neighbor.v] = new_distance;
            }
        }
        visited[current_vertex] = true;
    }

    std::cout << "Shortest Paths to All Vertices\n";
    for(int i : std::views::iota(0,this->size)){
        std::cout << i << "\t" << distances[i] << "\n";
    }
}

void Graph::dijkstra(int src, int dest) {
    std::vector<bool>visited(this->size, false);
    std::vector<int>distances(this->size, std::numeric_limits<int>::max());
    std::vector<int>predecessors(this->size);
    std::stack<int>path;

    int current_vertex = -1;
    distances[src] = 0;
    int smallest_distance;

    for(int vertex : std::views::iota(0, this->size)){
        smallest_distance = std::numeric_limits<int>::max();

        for(int candidate : std::views::iota(0, this->size)){
            if(current_vertex == dest) break;
            if(distances[candidate] < smallest_distance && !visited[candidate]){
                smallest_distance = distances[candidate];
                current_vertex = candidate;
            }
        }

        if(current_vertex == dest) break;

        for(Edge neighbor : this->adj[current_vertex]){
            int new_distance = distances[current_vertex] + neighbor.weight;
            if(new_distance < distances[neighbor.v]){
                distances[neighbor.v] = new_distance;
                predecessors[neighbor.v] = current_vertex;
            }
        }
        visited[current_vertex] = true;
    }

    std::cout << "Shortest Path From " << src << " to " << dest << "\n";

    while(current_vertex != src){
        path.push(current_vertex);
        current_vertex = predecessors[current_vertex];
    }
    path.push(src);

    while(!path.empty()){
        std::cout << path.top() << " ";
        path.pop();
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int size = 150;
    int s = rand() % size;
    int d = rand() % size;


    Graph g(size);

    int loop = rand() % size *1.5 + size;

    for (int i = 0; i < loop; ++i) {
        int src = rand() % size;
        int dest = rand() % size;
        int weight = rand() % 1000 + 1;
        g.add_edge(src, dest, weight);
    }

    // Print the graph
    g.print();
    g.DFS(s);
    std::cout << std::endl;
    g.BFS(s);
    std::cout << std::endl;
    g.dijkstra(s);
    g.dijkstra(s, d);
    return 0;
}