//
// Created by Nasir Alizade on 2023-03-30.
//

#include "Dijkstras.h"
#include <queue>
#include <vector>
#include <iostream>
#include <limits>

// Create a priority queue to hold the nodes to be visited, sorted by distance(weight)
using priority_queue_t = std::priority_queue<std::pair<int, node_id_t>, std::vector<std::pair<int, node_id_t>>, std::greater<>>;
void dijkstra(const adjacency_list_t &graph, node_id_t start, node_id_t end) {
    // Create a vector to hold the distance to each node from the start node
    constexpr double INF=std::numeric_limits<double>::max();
    std::vector<double> distance(graph.first.size(), INF);

    //  A vector to hold the parent node of each node in the shortest path
    std::vector<node_id_t> parent(graph.first.size(), -1);

    priority_queue_t pq;

    //lägg start nodet  i kön med längden 0
    pq.emplace(0, start);
    distance[start] = 0;

    while (!pq.empty()) {

        //hämta nodet med kortaste längden från start noden
        node_id_t curr_node = pq.top().second;
        pq.pop();
        // stop om vi har hittat målet
        if (curr_node == end) {
            break;
        }

        // Check all neighbors of the current node
        for (const auto& [n1,n2,weight,description]:graph.second) {
            if (n1==curr_node){
                double new_distance=distance[curr_node]+weight;
                if (new_distance < distance[n2]){
                    distance[n2]=new_distance;
                    parent[n2]=curr_node;
                    pq.emplace(new_distance,n2);
                }
            }
        }
    }

    //Skriv ut kortaste vägen från start till slutet
    if (parent[end] == -1) {
        std::cerr << "No path from " << start << " to " << end << "\n";
    } else {
        std::vector<node_id_t> path;
        node_id_t curr_node = end;
        while (curr_node != -1) {
            path.push_back(curr_node);
            curr_node = parent[curr_node];
        }
        std::cout << "Shortest path from " << start << " to " << end << ":\n";
        for (int i = path.size() - 1; i >= 0; --i) {
            std::cout << "--> " << graph.first.at(path[i]) << " \n ";
        }
        std::cout << "Path: ";
        for (int i = path.size() - 1; i >= 0; --i) {
            std::cout << path[i] << " ";
        }
        std::cout << "\nDistance: " << distance[end] << "\n";
    }
}
