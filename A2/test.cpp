//test
#include <iostream>
using namespace std;

int  BubbleSort(int A[], int size)			// main entry point
{
  /* Complete this function with the implementation of bubble sort algorithm 
     Record number of comparisons in variable num_cmps of class  Sort
  */
	int num_cmps = 0;
	for (int k = 1; k < size; k++) {
		bool cont = false;
		 for (int j = 0; j < size - k; j++) {
		 	if(A[j+1] < A[j]) { //swap A[j] and A[j+1]
		 		num_cmps++; // increase the number of comparisons
		 		int tmp = A[j];
		 		A[j] = A[j+1];
		 		cont =true;
		 	}
		 	num_cmps++; // make sure the last time's comparsion has been recorded
		 }
		 	num_cmps++; //count the number of comparison to compare cont and true
		 	if(!cont) break; //stop sorting
	}
}
int main()
{
	int a[]={6,5,4,3,2,1};
	BubbleSort(a,6);
	for(int i=0; i<6; i++)
		 		cout<< a[i]<< endl;

}
