// ***
// *** You must modify this file
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{	
	// argv[1]: name of input file (binary)
	// argv[2]: name of output file (binary)
	
	if(argc <  3){
		return EXIT_FAILURE;
	}

	int numElem;
	numElem = countVector(argv[1]);

	if(numElem < 1){
		return EXIT_FAILURE;
	}

	// if the number of vector is 0 or negative, return EXIT_FAILURE

	// otherwise, allocate memory for an array of vectors

	Vector *vecArr;
	vecArr = (Vector*)malloc(sizeof(Vector) * numElem);


	// read the vectors from the file whose name is argv[1]. save the
	// results in the allocated array
	// if reading fails, release memory and return EXIT_FAILURE

#ifdef DEBUG
	printVector(vecArr, numElem);
#endif  

<<<<<<< HEAD
	qsort(&argv[3], numElem, sizeof(Vector), compareVector);
	// call qsort to sort the vectors, use argv[3] to determine which
	// attribute to sort
=======
>>>>>>> fdda0c67c6732be4491fe3a3a328a4451aed0717

#ifdef DEBUG
	printf("\n");
	printVector(vecArr, numElem);
#endif  

	// write the sorted array to the file whose name is argv[2]
	// if writing fails, release memory and return EXIT_FAILURE

	writeVector(argv[2], vecArr, numElem);

	if(argv[2] == false){
		return EXIT_FAILURE;
	}
	
	free(vecArr);
	return EXIT_SUCCESS;
}
#endif
