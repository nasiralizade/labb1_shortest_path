//
// Created by Nasir Alizade on 2023-03-30.
//

#ifndef LABB1_BFS_H
#define LABB1_BFS_H
#include "reader.h"
void bfs(int start,const adjacency_list_t &list);
bool is_all_visited_bfs(const std::vector<bool> &visited);
bool verify_bfs(int start,adjacency_list_t &graph);
#endif //LABB1_BFS_H
