/*
csce221-507
Jialu Zhao
zhaojialu123@tamu.edu
*/

// please implement it
#include "Graph.hpp"

//default constructor has been constructed already

// constructor from adjl = adjacency list (optional)
Graph::Graph(vector<list<Edge>> adjl)
{
	adj_list = adjl;
} 

// build a graph from the adjacency list
void Graph::buildGraph(ifstream &in)
{
	int n,e; // number of vertices, edges
	in >> n >> e; // read n and e from input.data 

	// build vertices vector
	for(int i = 0; i < n; i++)
	{
		Vertex v = Vertex(i);
		vertices.push_back(v);
	}
	// build adjacency list
	for(int j = 0; j < n; j++)
	{
		int temp;
		in >> temp;
		while(temp != -1)
		{
			vertices[j].connectTo(temp);
			in >> temp;
		}
		adj_list.push_back(vertices[j].edgeList);
	}

}

//display the graph
void Graph::displayGraph(ostream &cout)
{
	for(int i = 0; i < vertices.size(); i++)
	{
		cout << vertices[i].label << ":"<<'\t';
		for(auto e : adj_list[i])
			cout << e.end << '\t';
		cout << endl;
	}
}
bool in_group(int s, vector<int> v)
{ 
	bool judge = false;
	for(int i = 0; i < v.size(); i++)
	{
		if(s == v[i])
			judge = true;
	}
	return judge;
}
// determine the possibility of partition the cities into two groups
void Graph::determine_partition()
{
	group1.push_back(0);
	group2.push_back(1);
	for(int i = 2; i < vertices.size(); i++)
	{
		if(in_group(vertices[i-1].label,group1))
		{
			bool alreay_done = false;
			bool judge1 = false;
			for(int j = 0; j < group1.size(); j++)
			{
				// judge if there is an edge or not
				for(auto e : adj_list[group1[j]])
				{
					if(vertices[i].label == e.end)
						judge1 = true;
				}
			}
			if(!judge1)
			{
				group1.push_back(vertices[i].label);
				alreay_done = true;
			}
			if(!alreay_done)
			{
			bool judge2 = false;
			for(int j = 0; j < group2.size(); j++)
			{
				// judge if there is an edge or not
				for(auto e : adj_list[group2[j]])
				{
					if(vertices[i].label == e.end)
						judge2 = true;
				}
			}
			if(!judge2)
				group2.push_back(vertices[i].label);
		}
		}
		else if(in_group(vertices[i-1].label,group2))
		{
			bool alreay_done = false;
			bool judge2 = false;
			for(int j = 0; j < group2.size(); j++)
			{
				// judge if there is an edge or not
				for(auto e : adj_list[group2[j]])
				{
					if(vertices[i].label == e.end)
						judge2 = true;
				}
			}
			if(!judge2)
			{
				group2.push_back(vertices[i].label);
				alreay_done = true;
			}
			if(!alreay_done)
			{
			bool judge1 = false;
			for(int j = 0; j < group1.size(); j++)
			{
				// judge if there is an edge or not
				for(auto e : adj_list[group1[j]])
				{
					if(vertices[i].label == e.end)
						judge1 = true;
				}
			}
			if(!judge1)
				group1.push_back(vertices[i].label);
		}
		}
		else 
		{
		cout << " such a grouping is not possible." << endl;
		throw 20;
		}
	}
	if(group1.size() + group2.size() != vertices.size())
	{
		// if this grouping is not existed, throw an exception
		cout << " such a grouping is not possible." << endl;
		throw 20;
	}
	else
	{
		cout << "Group1:" << '\t';
		for(int i = 0; i < group1.size(); i++)
			cout << group1[i] << '\t';
		cout << endl;
		cout << "Group2:" << '\t';
		for(int i = 0; i < group2.size(); i++)
			cout << group2[i] << '\t';
		cout << endl;

	}

}

// using for min priority queue
struct compare
{
  bool operator()(const Vertex& v1, const Vertex& v2)
  {
      return v1.d_value > v2.d_value;
  }
};

// find the shortest path for two given vertices
void Graph::find_shortest_path(Vertex v1, Vertex v2, Graph g)
{
	// if these two vertices are not in the same group or 
	//they don't exist in these groups, throw an exception
	bool find_v1_group1 = false;
	bool find_v1_group2 = false;
	bool find_v2_group1 = false;
	bool find_v2_group2 = false;

	// search v1 and v2 in group 1
	for(int i = 0; i < g.group1.size(); i++)
	{
		if(v1.label == g.group1[i])
			find_v1_group1 = true;
		if(v2.label == g.group1[i])
			find_v2_group1 = true;
	}

	// search v1 and v2 in group 2
	for(int i = 0; i < g.group2.size(); i++)
	{
		if(v1.label == g.group2[i])
			find_v1_group2 = true;
		if(v2.label == g.group2[i])
			find_v2_group2 = true;
	}
	
	bool both_in_group1 = find_v1_group1 && find_v2_group1;
	bool both_in_group2 = find_v1_group2 && find_v2_group2;
	
	if(!both_in_group1 &&!both_in_group2)
		throw 'a';

	//-------------------------------------------------------------
	// find the shortest path for two given vertices
	// using Dijkstra algorithm
	// initialize PQ to have all v
	priority_queue<Vertex,vector<Vertex>, compare > PQ;

	// initialize the start node's d_value to be 0
	vertices[v1.label].d_value = 0;

	for(int i = 0; i < vertices.size(); i++)
	{
		PQ.push(vertices[i]);
	}

	while(!PQ.empty())
	{
		Vertex u = Vertex(PQ.top().label);
		u.d_value = PQ.top().d_value;
		u.p_value = PQ.top().p_value;
		PQ.pop();

		for(auto e : adj_list[u.label])
		{
			if(vertices[e.end].d_value > u.d_value + 1)
			{
				vertices[e.end].d_value = u.d_value + 1;
				vertices[e.end].p_value = u.label;
			}
		}
		vertices[u.label].be_visited = true;
		while(!PQ.empty())
			PQ.pop();
			for(int i = 0; i < vertices.size(); i++)
		{
			if(vertices[i].be_visited == false)
			PQ.push(vertices[i]);
		}

	}
	

	// -------------------------------------------------------
	// output the shortest path
	int shorest_path;
	shorest_path = vertices[v2.label].d_value;
	cout << "The shortest path from " << v1.label << " to " << v2.label << " is " << shorest_path << "." << endl;
	// output the number of the stops
	cout << "The number of stops is: "; 
	vector<int> middle_stops;
	int middle_stop = v2.label;
	int number_stops = 0;
	while(middle_stop != -1)
		{
			middle_stop = vertices[middle_stop].p_value;
			middle_stops.push_back(middle_stop); 
			number_stops++;
		}
	cout << number_stops << "." << endl; 
	// output the middle stops
	cout << "All the vertices (cities) on this shortest path:" << endl;
	for(int i = middle_stops.size()-2; i >= 0; i--)
		cout << middle_stops[i] << "->";
	cout << v2.label;


}



