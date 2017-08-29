/* 
Jialu Zhao
username: zhaojialu123
section number: 507
email: zhaojialu123@tamu.edu
*/
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <fstream>
#include "HashTable.h"
using namespace std;

int main()
{
	// read the roster.csv containing students grades
	ifstream roster("roster.csv");
	string line1;
	int table_size = 0;

	// get the size of hash table
	while(getline(roster, line1))
	{
		table_size++;
	}
	roster.clear();
	roster.seekg(0,ios::beg);
	// construct the hash table
	HashTable Table(table_size);

	// read input.csv containing grades
	ifstream input("input.csv");
	string line2;

	// parser each row in input.csv
	while(getline(input,line2))
	{
		stringstream ss;
		ss >> line2;
		regex pattern{R"(([\s\S]+,)([\s\S]+)(,)([\s\S]+))"};  
      	smatch matches; 
      	regex_search(line2, matches, pattern);
      	Table.insert(stoi(matches[2].str()),stoi(matches[4].str()));
	}
	input.clear();
	input.seekg(0,ios::beg);

	// create the output file
	ofstream output;
	output.open("output.csv", ios::app);

	// parser each row in roster.csv
	while(getline(roster,line1))
	{
		stringstream ss;
		ss >> line1;
		regex pattern{R"(([\s\S]+),([\s\S]+),([\s\S]+),)"};
		smatch matches;
		regex_search(line1, matches, pattern);
		if(Table.search(stoi(matches[3].str())) > 100)
			output << line1 << endl;
		else
		{
			output << matches[1] << ',' << matches[2] << ',' << matches[3] << ',' << Table.search(stoi(matches[3].str())) << endl;
		}

	}
	roster.clear();
	roster.seekg(0,ios::beg);
	// Display the statistics about the hash table
	 cout << "The maximum length of the linkedlist in the hash table:" << Table.get_max() << endl;
	 cout << "The minimum length of the linkedlist in the hash table:" << Table.get_min() << endl;
	 cout << "The average length of the linkedlist in the hash table:" << Table.get_average() << endl;






}