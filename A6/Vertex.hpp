/*
csce221-507
Jialu Zhao
zhaojialu123@tamu.edu
*/

#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include <list>
#include <string>
#include <vector>

#include "Edge.hpp"
using namespace std;

class Vertex {
public:
    // the label of this vertex
    int label;
    int d_value = 100000; //using for get distance
    int p_value = -1; // using for get parent
    bool be_visited = false; // using to judge if that's been visited or not
    // using a linked-list to manage its edges which offers O(c) insertion
    list<Edge> edgeList;
    
    // init your vertex here
    Vertex(int l);  //constructor
    
    // connect this vertex to a specific vertex (adding edge)
    void connectTo(int end);
};

#endif /* Vertex_hpp */
