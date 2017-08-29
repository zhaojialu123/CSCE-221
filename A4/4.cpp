#include <iostream> 
#include <string> 
#include <regex>
using namespace std; 
int main() { 
   regex pattern{R"((<head>)([\s\S]+)(<title>[\s\S]+</title>)([\s\S]+)(</head>))"}; 
   string to_search = "<html><head>Wow such a header <title>This is a title</title>"
                    "So top</head>Much body</html>"; 
   smatch matches; 
   regex_search(to_search, matches, pattern); 
   cout << matches[2] << endl; 
   cout << matches[4] << endl; 
   return 0; 
}