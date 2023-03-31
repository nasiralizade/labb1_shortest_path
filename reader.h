//
// Created by Nasir Alizade on 2023-03-30.
//

#ifndef LABB1_READER_H
#define LABB1_READER_H

#include <string>
#include <map>
#include <ostream>

using node_id_t = int;
using weight_t = double;
using meta_t = std::map<node_id_t, std::string>;

struct edge{
    node_id_t n1;
    node_id_t n2;
    weight_t weight;
    std::string description;
};

using edge_list_t = std::vector<edge>;

using adjacency_list_t = std::pair<meta_t ,edge_list_t >;

adjacency_list_t parse_file(std::string filename);

#endif //LABB1_READER_H
