/*
csce221-507
Jialu Zhao
zhaojialu123@tamu.edu
*/

#ifndef Edge_hpp
#define Edge_hpp

#include <stdio.h>

class Edge {
public:
    // start vertex's label
    int start;
    // end vertex's label
    int end;
    // the weight of this edge
    int weight;
    // constructor
    Edge(int s, int e, int w);
};

#endif /* Edge_hpp */
