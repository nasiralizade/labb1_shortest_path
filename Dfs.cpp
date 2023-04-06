//
// Created by Nasir Alizade on 2023-03-30.
//

#include <vector>
#include <iostream>
#include "Dfs.h"

void dfs(const adjacency_list_t &graph) {
    std::vector<bool> visited(graph.first.size(), false);
    stack s;

    s.push(graph.first.begin()->first);
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

bool is_all_visited(const std::vector<bool> &visited) {
    return std::find(visited.begin(), visited.end(), false) == visited.end();
}
