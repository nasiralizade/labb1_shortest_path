//
// Created by Nasir Alizade on 2023-03-30.
//

#include "Bfs.h"
#include <queue>
#include <vector>
#include <iostream>

void bfs(int start,const adjacency_list_t &list) {

    std::vector<bool> visited(list.first.size(), false);
    std::queue<node_id_t> q;
    q.push(start);
    visited[q.front()] = true;
    while (!q.empty()) {
        node_id_t curr = q.front();
        q.pop();
        //kollar grannar till den nuvarande node
        for (auto &edge: list.second) {
            //om det finns grannar och dem är ej visited, lägg den i kön
            if (edge.n1 == curr && !visited[edge.n2]) {
                q.push(edge.n2);
                visited[edge.n2] = true;
            }
        }
    }
    /*if (std::all_of(visited.begin(), visited.end(), [](bool v) { return v; })) {
        std::cout << "BFS traversal is valid\n";
    }*/
    if (std::find(visited.begin(),visited.end(), false)==visited.end()){
        std::cout << "BFS traversal is valid\n";
    }else {
        std::cout << "BFS traversal is invalid\n";
        for (int node_id = 0; node_id < visited.size(); ++node_id) {
            if (!visited[node_id]) {
                std::cerr << "Node " << list.first.find(node_id)->second << " (id=" << list.first.find(node_id)->first
                          << ") is not visited\n";
            }
        }
    }
}



