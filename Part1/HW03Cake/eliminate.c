// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
	// allocate an arry of n elements
	int * arr = malloc(sizeof(* arr) * n);
	// check whether memory allocation succeeds.
	// if allocation fails, stop
	if (arr == NULL)
	{
		fprintf(stderr, "malloc fail\n");
		return;
	}

	for(int i = 0;i < n;i++){
		arr[i] = 1;
	}
	//int lcv = 1; //outer loop control variable
	int shift = k - 1; //how far the shift is for who becomes eliminated
	int elim = 0; //counter of people eliminated

	while(elim < n){
		elim = 0;
		for(int i = 0;i < n;i++){
			if(arr[i] == 'X'){
				elim++; //this section of the loop counts how many eliminated people there are (marked by X in the arrays)
			}else{
				if(shift != 0){
					shift--;
				}else{	
					printf("%d\n", i);
					shift = k - 1;
					arr[i] = 'X';
				}
			}
		}
	}

	free (arr);
}
#endif
