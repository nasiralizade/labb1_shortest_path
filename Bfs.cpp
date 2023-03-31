//
// Created by Nasir Alizade on 2023-03-30.
//

#include "Bfs.h"
#include <queue>
#include <vector>
#include <iostream>

void bfs(const adjacency_list_t &list) {
    std::vector<bool> visited(list.first.size(), false);
    std::queue<node_id_t> q;
    q.push(list.first.begin()->first);
    visited[q.front()] = true;
    while (!q.empty()) {
        node_id_t curr = q.front();
        q.pop();
        for (auto &edge: list.second) {
            if (edge.n1 == curr && !visited[edge.n2]) {
                q.push(edge.n2);
                visited[edge.n2] = true;
            }
        }
    }
    if (std::all_of(visited.begin(), visited.end(), [](bool v) { return v; })) {
        std::cout << "BFS traversal is valid\n";
    } else {
        std::cout << "BFS traversal is invalid\n";
        for (size_t node_id = 0; node_id < visited.size(); ++node_id) {
            if (!visited[node_id]) {
                std::cerr << "Node " << list.first.find(node_id)->second << " (id=" << list.first.find(node_id)->first
                          << ") is not visited\n";
            }
        }
    }
}

bool isAllVisitedBfs(const std::vector<bool> &visited) {
    return (std::find(visited.begin(), visited.end(), false) == visited.end());
}
