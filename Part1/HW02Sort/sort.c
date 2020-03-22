// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int * arr, int size)
	// a static function is visible only in this file
	// This function returns true if the array elements are
	// in the ascending order.
	// false, otherwise
{
	int ind;
	for (ind = 0; ind < (size - 1); ind ++)
	{
		if (arr[ind] > arr[ind + 1])
		{
			return false;
		}
	}
	return true;
}


// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void ssort(int * arr, int size)
{
	//int i; //outer loop control variable
	//int j; //inner loop control variable
	//int pos; //position of minimum in array
	//int temp; //temporary variable to hold minimum
	//int min; //found minimum value

	// This function has two levels of for
	// The first level specifies which element in the array
	// The second level finds the smallest element among the unsorted
	// elements

	for(int i = 0;i < size;i++)
	{
		int pos = i;	
		int dupC = 0; //duplicate counter
		for(int j = i;j < size;j++)
		{ 
			if(arr[j] < arr[pos])
			{
				pos = j; //records the position this minimum is in in the array
			}
			if(arr[j] == arr[pos])
			{
				dupC++;	
			}
		}
		int temp = arr[pos]; //assigns a temporary minimum value to temp
		arr[pos] = arr[i + dupC]; //places value in arr[i] in place of unsorted minimum value
		while(dupC != 0)
		{ 
			arr[i] = temp; //places minimum value in arr[i] (increases sorted list by 1)
			dupC--;
			i++;
		}
	} 
	// After finding the smallest element among the unsorted elements,
	// swap it with the element of the index from the first level
}
#endif
