//============================================================================
// Name        : bubble-sort.cpp
// Author      : Jialu Zhao
// Date        : 02/07/2017
// Copyright   : 
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"

void 
BubbleSort::sort(int A[], int size)			// main entry point
{
  /* Complete this function with the implementation of bubble sort algorithm 
     Record number of comparisons in variable num_cmps of class  Sort
  */
	for (int k = 1; k < size; k++) {
		bool cont = false;
		 for (int j = 0; j < size - k; j++) {
		 	if(A[j+1] < A[j]) { //swap A[j] and A[j+1]
		 		int tmp = A[j];
		 		A[j] = A[j+1];
		 		cont =true;
		 	}
		 	num_cmps++; // increase the number of comparisons
		 }
		 	num_cmps++; //count the number of comparison to compare cont and true
		 	if(!cont) break; //stop sorting
	}
}
