// Jialu Zhao
// csce 221-507
// hw1-problem1
// 02/08/2017
#include <vector>
#include <iostream>
using namespace std;

//binary-sort for a vector
int binary_search(vector<int> A, int n, int x, int& con, char cc) {
  int mid, low = 0, high = n-1;
  while ( low <= high ) {
    con++;
    mid = (low + high)/2;
    if(cc == 'a'){ // ascending ordered vector
      if ( A[mid] < x ) 
        low = mid+1;
      else if( A[mid] > x ) 
        high = mid-1;
      else return mid; // found target in ascending order vector
  }
  else{ // descending order vector
      if ( A[mid] > x ) 
        low = mid+1;
      else if( A[mid] < x ) 
        high = mid-1;
      else return mid; // found target in descending ordered vector
  }
}
  return -1; // not found
}
// according to user's willing to generate vector
vector<int> vector_generator(int n, char c)
{
	vector <int> v;
	if(c == 'a'){
		// generate ascending vector
		for(int i = 1; i <= n; i++)
			v.push_back(i);
		return v;
	}
	else if(c == 'd'){
		// generate descending vector
			for(int i = n; i >= 1; i--)
			v.push_back(i);
			return v;
		}
		else 
			cout << "Invaild input!!!" << endl; // invaild input
}

// judge if the vector is ordered
bool judging_order(vector <int> v){
	int judge1 = 0;
    int judge2 = 0;
    bool order = true;
    // checking for ascending order vector
  	for(int i = 0; i < v.size()-1; i++)
  	{
  		if(v[i] <= v[i+1])
  			judge1 ++;
  	} 
  	//checking for descending order vector 
  	for(int i = 0;i < v.size()-1; i++)
  	{
  		if(v[i] >=v [i+1])
  			judge2++;
  	}
  	// if the vector is unordered, throw an exception
  	if(judge1 != 0 && judge2 != 0 )
  		order = false;
  	return order;
}

int main()
try
{
	// prompt users to enter the range 
	cout << "please enter the number of the range:" << endl;
	int range;
	cin >> range;
	// prompt users to choose from ascending or descending order
	cout << " Please choose to generate ascending or descending vector:" << endl;
	cout << " ( Enter a (for ascending) or d (for descending))" << endl;
	char choice;
	cin >> choice;
	// find target for a vector
	int target;
  	cout << " Please input target:" << endl;
  	cin >> target;
  	// generate the vector based on the user's choice
	vector <int> vect;
	vect = vector_generator(range,choice);
	// judging the vector if that is ordered
	bool ifordered = judging_order(vect);
	//if the vector is not ordered, throw an exception
	if(ifordered == false)
		throw 20;
	// count using for comparison
	int count = 0;
	// output the index of target
	cout << binary_search(vect, vect.size(),target,count,choice) << endl;
	// ouput the comparison times
	cout << count << endl;
}
catch(int) {// catch unordered error
    cerr << " Unordered vector!!!" << endl;
  }
  catch(...) {// catch other errors
    cerr << "Uncaught error: " << endl;
  }
 
