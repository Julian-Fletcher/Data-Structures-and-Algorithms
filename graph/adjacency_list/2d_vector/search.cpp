#include "graph.h"
#include <queue>
#include <stack>
#include <unordered_set>

void BFS(Undirected_Graph &g, char start){
    std::queue<char> nodes;
    std::unordered_set<char> visited;
    std::cout << "Breadth First Search (Undirected Graph) Starting at Node " << start << ": ";
    char current_node;
    nodes.push(start);
    while(!nodes.empty()){
        // Set current node to front of queue and remove it
        // Mark node as visited
        if(visited.count(nodes.front()) != 0){
            nodes.pop();
            continue;
        }
        current_node = nodes.front();
        nodes.pop();

        std::cout << current_node << " ";
        // Add current node to the list of visited nodes
        visited.insert(current_node);

        size_t index = locate_vertex(g.adj_list, current_node);

        // Push every edge into the queue
        for(Edge edge : g.adj_list[index]){
            if(visited.count(edge.node) != 0) continue;
            nodes.push(edge.node);
        }

    }
    std::cout << std::endl;
}

void BFS(Directed_Graph &g, char start){
    std::queue<char> nodes;
    std::unordered_set<char> visited;
    std::cout << "Breadth First Search (Directed Graph) Starting at Node " << start << ": ";
    char current_node;
    nodes.push(start);
    while(!nodes.empty()){
        // Set current node to front of queue and remove it
        // Mark node as visited
        if(visited.count(nodes.front()) != 0){
            nodes.pop();
            continue;
        }
        current_node = nodes.front();
        nodes.pop();

        std::cout << current_node << " ";
        // Add current node to the list of visited nodes
        visited.insert(current_node);

        size_t index = locate_vertex(g.adj_list, current_node);

        // Push every edge into the queue
        for(Edge edge : g.adj_list[index]){
            if(visited.count(edge.node) != 0) continue;
            nodes.push(edge.node);
        }

    }
    std::cout << std::endl;
}

void DFS(Undirected_Graph &g, char start){
    std::stack<char> nodes;
    std::unordered_set<char> visited;
    std::cout << "Depth First Search (Undirected Graph) Starting at Node " << start << ": ";
    char current_node;
    nodes.push(start);
    while(!nodes.empty()){
        // Set current node to front of queue and remove it
        // Mark node as visited
        if(visited.count(nodes.top()) != 0){
            nodes.pop();
            continue;
        }
        current_node = nodes.top();
        nodes.pop();

        std::cout << current_node << " ";
        // Add current node to the list of visited nodes
        visited.insert(current_node);

        size_t index = locate_vertex(g.adj_list, current_node);

        // Push every edge into the queue
        for(Edge edge : g.adj_list[index]){
            if(visited.count(edge.node) != 0) continue;
            nodes.push(edge.node);
        }

    }
    std::cout << std::endl;
}

void DFS(Directed_Graph &g, char start){
    std::stack<char> nodes;
    std::unordered_set<char> visited;
    std::cout << "Depth First Search (Undirected Graph) Starting at Node " << start << ": ";
    char current_node;
    nodes.push(start);
    while(!nodes.empty()){
        // Set current node to front of queue and remove it
        // Mark node as visited
        if(visited.count(nodes.top()) != 0){
            nodes.pop();
            continue;
        }
        current_node = nodes.top();
        nodes.pop();

        std::cout << current_node << " ";
        // Add current node to the list of visited nodes
        visited.insert(current_node);

        size_t index = locate_vertex(g.adj_list, current_node);

        // Push every edge into the queue
        for(Edge edge : g.adj_list[index]){
            if(visited.count(edge.node) != 0) continue;
            nodes.push(edge.node);
        }

    }
    std::cout << std::endl;
}