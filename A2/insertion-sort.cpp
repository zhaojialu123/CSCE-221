//============================================================================
// Name        : insertion-sort.cpp
// Author      : 
// Date        :
// Copyright   : 
// Description : Implementation of insertion sort in C++
//============================================================================

#include "sort.h"

void
InsertionSort::sort(int A[], int size)				// main entry point
{
  /* Complete this function with the implementation of insertion sort algorithm 
  Record number of comparisons in variable num_cmps of class Sort
  */
	for (int k = 1; k < n; k++ )
	{
		int tmp = A[k];
		int j = k;
		for( ; j > 0 && tmp < A[j-1]; j--)
		{
			num_cmps = num_cmps + 2; // compare j and 0, tmp and A[j-1], so increase the number by two
			A[j] = A[j-1];
		}
		A[j] = tmp;
		num_cmps = num_cmps + 2; // make sure the last time's comparison was counted
	}
}

