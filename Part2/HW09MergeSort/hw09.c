// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
	printf("%s(%6d, %6d, %6d)", msg, l, m, r);
	int ind;
	for (ind = l; ind <= r; ind ++)
	{
		printf("%d\n", arr[ind]);
	}
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
	// use fopen to open the file for read
	// return false if fopen fails

	FILE *fhlr;
	fhlr = fopen(filename, "r");
	if(fhlr == NULL){
		return false;
	}
	
	int nInt;

	// use fseek to go to the end of the file
	// check whether fseek fails
	// if fseek fails, fclose and return false


	if(fseek(fhlr, 0, SEEK_END) != 0){
		fclose(fhlr);
		return false;
	}


	// use ftell to determine the size of the file

	nInt = ftell(fhlr);


	// use fseek to go back to the beginning of the file
	// check whether fseek fails

	if(fseek(fhlr, 0, SEEK_SET) != 0){
		fclose(fhlr);
		return false;
	}


	// if fseek fails, fclose and return false



	// the number of integers is the file's size divided by
	// size of int  

	int szArr;
	szArr = nInt / sizeof(int);

	// allocate memory for the array
	
	int *tArr;
	tArr = (int*)malloc(nInt);

	*arr = (int*)malloc(nInt);
	
	if(arr == NULL){
		fclose(fhlr);
		return false;
		// if malloc fails, fclose and return false
	}

	if(tArr == NULL){
		fclose(fhlr);
		return false;
		// if malloc fails, fclose and return false
	}

	// use fread to read the number of integers in the file

	if(fread(tArr, sizeof(int), szArr, fhlr) != szArr){
		// if fread does not read the correct number
		// release allocated memory
		// fclose
		// return false
		fclose(fhlr);
		return false;
	}else{
		fclose(fhlr);
	}  
	// if fread succeeds
	// close the file




	// update the argument for the array address

/*	for(int i = 0;i < szArr;i++){
		arr[i] = &tArr[i];
	}*/

	arr = &tArr;

	// update the size of the array

	size = &szArr;

	//free(tArr);

	return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
	FILE *fhlr;
	fhlr = fopen(filename,"w");
	if(fhlr == NULL){
		return false;
	}

	// use fwrite to write the entire array to a file

	int nInt;
	nInt = sizeof(int);
	if(fwrite(arr, sizeof(int), nInt, fhlr) != size){
		fclose(fhlr);
		return false;
	}else{
		return true;
	}

	// check whether all elements of the array have been written
	// fclose
	// if not all elements have been written, return false
	// if all elements have been written, return true
}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int * arr, int l, int m, int r)
	// a static function can be called within this file only
	// a static function is invisible to other files
{
	// at the beginning of the function
#ifdef DEBUG
	// Do not modify this part between #ifdef DEBUG and #endif
	// This part is used for grading. 
	printInput("Merge in", arr, l, m, r);
#endif

	// if one or both of the arrays are empty, do nothing
	
	
	int *bArr; //backup array
	bArr = (int*)malloc((r - l) * sizeof(int));

	if((&arr[l] != NULL && &arr[r] != NULL) || l != r){

		int lSort = 0; //left elements sorted
		int rSort = 0; //right elements sorted
		while((lSort + rSort) != (r - l)){
			if(arr[l + lSort] < arr[m + 1 + rSort]){
				bArr[l + (lSort + rSort)] = arr[l + lSort];
				lSort++;
			}else{	
				bArr[l + (lSort + rSort)] = arr[m + 1 + lSort];
				rSort++;
			}
		}
	}

	// Hint: you may consider to allocate memory here.
	// Allocating additiional memory makes this function easier to write




	// merge the two parts (each part is already sorted) of the array
	// into one sorted array

	for(int i = l;i <= r;i++){
		arr[i] = bArr[i];
	}//copy array from backup

	free(bArr);

	// the following should be at the bottom of the function
#ifdef DEBUG
	// Do not modify this part between #ifdef DEBUG and #endif
	// This part is used for grading. 
	printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
	// at the beginning of the function
#ifdef DEBUG
	// Do not modify this part between #ifdef DEBUG and #endif
	// This part is used for grading. 
	printInput("mergeSort", arr, l, r, -1);
#endif

	// if the array has no or one element, do nothing

	if(l <= r){
		int mid = l + (r - l) / 2;
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}

	// divide the array into two arrays
	// call mergeSort with each array
	// merge the two arrays into one	
} 
#endif
