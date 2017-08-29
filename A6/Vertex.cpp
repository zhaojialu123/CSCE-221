/*
csce221-507
Jialu Zhao
zhaojialu123@tamu.edu
*/

// please implement it

#include "Vertex.hpp"

// constructor
Vertex::Vertex(int l)
{
	label = l;
}

// connect this vertex to a specific certex(adding edge)
void Vertex::connectTo(int end)
{
	Edge new_edge = Edge(label,end,1);
	edgeList.push_back(new_edge);
}
