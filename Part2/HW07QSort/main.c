// ***
// *** You must modify this file
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw07.h"

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
<<<<<<< HEAD
	// argv[1]: name of input file
	// argv[2]: name of output file

	if(argc != 3){
		return EXIT_FAILURE;
	}

	// count the number of integers in the file
	int numElem = 0;
	numElem = countInt(argv[1]);

	if (numElem == -1){
		return EXIT_FAILURE;
	}

	// allocate memory for the integers in the file
	// 1. create a pointer variable
	// 2. allocate memory
	// 3. check whether allocation succeed
	//    if allocation fails, return EXIT_FAILURE

	int * intArr;

	intArr = (int*)malloc(sizeof(int) * numElem);

	if(intArr == NULL){
		return EXIT_FAILURE;
	}

	bool rtv = readInt(argv[1], intArr, numElem);

	if (rtv == false){
		return EXIT_FAILURE;  
	}

	qsort(intArr,numElem,sizeof(int),compareInt);

	// write the sorted array to a file whose name is argv[2]

	rtv = writeInt(argv[2], intArr, numElem);
	if (rtv == false)
	{
		free(intArr);
		return EXIT_FAILURE;
	}

	free(intArr);

	return EXIT_SUCCESS;
=======
  // argv[1]: name of input file
  // argv[2]: name of output file

  // if argc is not 3, return EXIT_FAILURE

  // count the number of integers in the file
  int numElem = 0;
  numElem = countInt(argv[1]);

  if (numElem == -1) // fopen fails
    {
      return EXIT_FAILURE;
    }

  // allocate memory for the integers in the file
  // 1. create a pointer variable
  // 2. allocate memory
  // 3. check whether allocation succeed
  //    if allocation fails, return EXIT_FAILURE

  int * intArr;

  bool rtv = readInt(argv[1], intArr, numElem);

  if (rtv == false) //if read fails, return EXIT_FAILURE
    { 

    }
  
  // call qsort using the comparison function you write
  qsort(....);

  // write the sorted array to a file whose name is argv[2]
  
  rtv = writeInt(argv[2], intArr, numElem);
  if (rtv == false) // read fail
    {
      // release memory
      return EXIT_FAILURE;
    }

  // everything is ok, release memory, return EXIT_SUCCESS

  return EXIT_SUCCESS;
>>>>>>> fdda0c67c6732be4491fe3a3a328a4451aed0717
}
#endif

