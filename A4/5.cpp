#include <iostream> 
#include <string> 
#include <regex>
#include <fstream>
using namespace std; 
int main() { 
   ifstream infile;
   infile.open("stroustrup.txt");
   string to_search;
   while(getline(infile,to_search)) // read from input file line by line
   {
      regex pattern{R"((<a href=")([\s\S]+.ppt)(">[\s\S]+</a>))"};  
      smatch matches; 
      regex_search(to_search, matches, pattern);
      if(matches[2] != "") 
      cout << matches[2] << endl; 

   }
   infile.close(); 
   return 0; 
}