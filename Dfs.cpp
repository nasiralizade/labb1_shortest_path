//
// Created by Nasir Alizade on 2023-03-30.
//

#include <vector>
#include <iostream>
#include "Dfs.h"


void dfs(int start, std::vector<bool> &visited, adjacency_list_t &graph) {
    stack s;
    s.push(start);
    while (s.size()){
        auto curr_node=s.pop();
        if (visited[curr_node]){
            continue;
        }
        visited[curr_node]= true;
        for (auto &edge:graph.second) {
            if (edge.n1==curr_node && !visited[edge.n2]){
                s.push(edge.n2);
            }
        }
    }
}


bool is_all_visited(const std::vector<bool> &visited) {
    return std::find(visited.begin(), visited.end(), false) == visited.end();
}

bool verifyMatrix(adjacency_list_t test) {
    std::vector<bool>visited(test.first.size(), false);
    for (int i = 0; i < test.first.size(); ++i) {
        dfs(i,visited,test);
        if (!is_all_visited(visited)){
            return false;
        }
        std::fill(visited.begin(), visited.end(), false);
    }
    return true;
}




/*
void dfs2(const adjacency_list_t &graph) {
    std::vector<bool> visited(graph.first.size(), false);
    stack s;
    int start_node=0;
    std::cout<<"Ange start node-> ";
    std::cin>>start_node;
    s.push(graph.first.begin()->first);
    //s.push(start_node);
    while (s.size()) {
        auto curr_node = s.pop();
        if (visited[curr_node]) {
            continue;
        }
        visited[curr_node] = true;
        for (const auto &edge: graph.second) {
            if (edge.n1 == curr_node && !visited[edge.n2]) {
                s.push(edge.n2);
            }
        }
    }
    if (is_all_visited(visited)) {
        std::cout << "DFS traversal is valid\n";
    } else {
        std::cout << "DFS traversal is invalid\n";
        for (int node_id = 0; node_id < visited.size(); ++node_id) {
            if (!visited[node_id]) {
                std::cerr << "Node " << graph.first.find(node_id)->second << " (id=" << graph.first.find(node_id)->first
                          << ") is not visited\n";
            }
        }
    }
}

*/
