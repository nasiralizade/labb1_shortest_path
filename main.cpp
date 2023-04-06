#include <iostream>
#include <vector>
#include "reader.h"
#include "Dfs.h"
#include "Bfs.h"
#include "Dijkstras.h"
void menu(const adjacency_list_t& test);

int main() {
    std::vector<int> v(200);
    //grafen är inte sammanhängande, node 19 går till node 3, men ingen node som går till 19
    //mellan Nackstavägen till Förrådet
    //start node 23 och slut node 37
    //Path:23 1 2 3 4 5 6 7 8 10 28 37
    //Sträckan: 1620.21
    //////////////////////////////////////////////////
    //mellan L319 och D025
    //start node 46 och slut node 47
    //Path: 46 44 30 20 10 28 47
    //Sträckan:Distance: 479.65
    //////////////////////////////////////////////////
    //från Universitetet till Bite Line Västra
    //start node 20 och slut node 19
    //No path from 20 to 19
    // Path: 20 10 8 7 6 5 4 3 19
    //Sträckan 1207.5

    const std::string filename = "export.txt";
    const adjacency_list_t test = parse_file(filename);
    menu(test);
    return 0;
}

void menu(const adjacency_list_t& test) {
    while (true) {
        std::cout << "Enter 1 for DFS, 2 for BFS, 3 for Dijkstra's Algorithm, 4 to Exit:\n "<<"--> ";
        int choice;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            dfs(test);
        } else if (choice == 2) {
            bfs(test);
        } else if (choice == 3) {
            int start, end;
            std::cout << "Enter the start node id: ";
            std::cin >> start;
            if (std::cin.fail() || !test.first.count(start)) {
                std::cout << "Invalid node id.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cout << "Enter the end node id: ";
            std::cin >> end;
            if (std::cin.fail() || !test.first.count(end)) {
                std::cout << "Invalid node id.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            dijkstra(test, start, end);
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }
}
