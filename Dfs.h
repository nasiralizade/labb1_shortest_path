//
// Created by Nasir Alizade on 2023-03-30.
//

#ifndef LABB1_DFS_H
#define LABB1_DFS_H
#include "reader.h"
#include <stack>

struct stack {
    std::stack<node_id_t> data;
    node_id_t pop() {
        node_id_t node = data.top();
        data.pop();
        return node;
    }
    void push(node_id_t node_id) {
        data.push(node_id);
    }
    size_t size() {
        return data.size();
    }
};



void dfs(int start,std::vector<bool>&visited, adjacency_list_t& graph);
bool verifyMatrix(adjacency_list_t test);
bool is_all_visited(const std::vector<bool>& visited);
//void resetVisited(std::vector<bool> visited);
//void dfs2(const adjacency_list_t& graph);

#endif //LABB1_DFS_H
