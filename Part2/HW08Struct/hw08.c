// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
	// count the number of vectors in the file and return the number
	// The input is a binary file. You must use fread.
	// You must not use fscanf(, "%d", ) 

	FILE *fhlr;
	fhlr = fopen(filename,"r");

	if(fhlr == NULL){
		return -1;
	}	

	int *spc = (int*)malloc(sizeof(int) * 1); 

	int count;
	count = fread(&spc,sizeof(int),1,fhlr); //unsure if last argument is right, but other part is right

	// If fopen fails, return -1
	//
	//
	// For the mode of fopen, you may use "r" without b
	//

	fclose(fhlr);
	return count;
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
	// read Vectors from the file.

	FILE *fhlr;
	fhlr = fopen(filename,"r");

	if(fhlr == NULL){
		return false;
	}	

	int *spc = (int*)malloc(sizeof(int) * 1);

	int count;
	count = fread(&spc,sizeof(int),1,fhlr);

	if(count != size){
		return false;
	}

	//
	// if the number of integers is different from size (too
	// few or too many) return false

	fclose(fhlr);
	return true;
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
	if(p1 <  p2){
		return(-1);
	}else if(p1 > p2){
		return(1);
	}

	return(0);
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{	
	FILE *fhlr;
	fhlr = fopen(filename,"w");

	if(fhlr == NULL){
		return false;
	}	
	
	// write the array to file using fwrite
	// need to check how many have been written
	// if not all are written, fclose and return false

	for(int i = 0;i < size;i++){
		fwrite(vecArr, sizeof(Vector), size, fhlr);
		if(vecArr == NULL){
			fclose(fhlr);
			return false;
		}
	}

	fclose(fhlr);
	return true;
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
	int ind = 0;
	for (ind = 0; ind < size; ind ++)
	{
		printf("%6d %6d %6d\n",
				vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
	}
}
