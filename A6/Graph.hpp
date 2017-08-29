/*
csce221-507
Jialu Zhao
zhaojialu123@tamu.edu
*/

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <queue> // using priority queue



#include "Vertex.hpp"

using namespace std;

class Graph {
public:
    // we use a vector to store vertices in the graph
    // and use label (int) to be a subscript to access a vertex
    vector<list<Edge>> adj_list; // adjacency list
    vector<Vertex> vertices;  // all vertices
    vector<int> group1;
    vector<int> group2;
    Graph(){}// default constructor
    Graph(vector<list<Edge>> adjl); // constructor from adjl = adjacency list (optional)
    void buildGraph(ifstream &in);  // build a graph from the adjacency list
    void displayGraph(ostream &cout);  // display the graph
    void determine_partition(); // determine the possibility of partition the cities into two groups
    void find_shortest_path(Vertex v1, Vertex v2, Graph g); // find the shortest path
};

#endif /* Graph_hpp */
