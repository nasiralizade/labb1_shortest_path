//
// Created by Nasir Alizade on 2023-03-30.
//

#ifndef LABB1_BFS_H
#define LABB1_BFS_H
#include "reader.h"
void bfs(const adjacency_list_t &list);

std::vector<node_id_t> getUnvisitedNeighboursBfs(node_id_t curr, const adjacency_list_t &pair, std::vector<bool> visited);
bool isVisitedBfs(node_id_t node, const std::vector<bool> &visited) ;
bool isAllVisitedBfs(const std::vector<bool> &visited) ;
#endif //LABB1_BFS_H
