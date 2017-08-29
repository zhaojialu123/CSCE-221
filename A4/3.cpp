#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main() {
	regex pattern{R"((\d\d)([\s\S]+)(thanks))"};
	string to_search = "I would like the number 98"
	" to be found and printed, thanks.";
	smatch matches;
	regex_search(to_search, matches, pattern);
	cout << matches[1] << endl;
	cout << matches[3] << endl;
	return 0;
}