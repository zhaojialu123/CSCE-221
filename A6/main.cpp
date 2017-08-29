/*
csce221-507
Jialu Zhao
zhaojialu123@tamu.edu
*/

#include <iostream>
#include <string>

#include "Graph.hpp"

int main(int argc, const char * argv[]) {
    try{
        if (argc != 2) throw invalid_argument("Usage: ./main <file name>");
        ifstream in(argv[1]);
        if (!in) throw invalid_argument("Invalid file name or unable to open file.");
        Graph g;
        g.buildGraph(in);
        g.displayGraph(cout);
        g.determine_partition();
        int start;
        int end;
        cout << "Please choose two cities which you want to find the shortest path between them:" << endl;
        cout << "(Note: Choose from the same group, using space to seperate them!!)" << endl;
        cin >> start >> end;
        g.find_shortest_path(Vertex(start),Vertex(end),g);
        return 0;
    }
    catch(int)
    {
        cerr << "This grouping is not existed, so can't find the shortest path from cities." << endl;
    }
    catch(char)
    {
        cerr << "These two vertices are not in the same group or they don't exist in these groups!!" << endl;
    }
    catch (exception& error){
        cerr << "Error: " << error.what() << endl;
    }
}
