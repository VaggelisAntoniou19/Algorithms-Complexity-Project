/*
 * greedy.hpp
 *
 */

#ifndef GREEDY_HPP_
#define GREEDY_HPP_
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include "input.hpp"
using namespace std;

class Graph
{
    int V; // No. of vertices
    std::string filename;
    list<int> *adj; // A dynamic array of adjacency lists
public:
    
    Graph(input &in);
    ~Graph();
     void save_to_file(int total);
    void fill_Graph(const input &in);
    void greedyColoring();
};


#endif /* GREEDY_HPP_ */
