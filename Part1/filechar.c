// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, char * counts, int size)
{
	// open a file whose name is filename for reading
	// if fopen fails, return false. Do NOT fclose
	// if fopen succeeds, read every character from the file
	FILE * fiHol;
	fiHol = fopen(const char *filename,"r");

	if(fiHol == NULL){
		printf("\nCould not open file");
		return(0);
	}
	// if a character (call it onechar) is between
	// 0 and size - 1 (inclusive), increase
	// counts[onechar] by one
	// You should *NOT* assume that size is 256
	// reemember to call fclose
	// you may assume that counts already initialized to zero
	// size is the size of counts
	// you may assume that counts has enough memory space 
	int onechar = 0;
	char endTest;  //tests for EOF
	
	if(onechar >= 0 && onechar <= (size - 1)){
		counts[onechar]++;
		
		endTest = fgetc(fiHol);

		if(endTest == EOF){
		onechar = size;
		fclose(fiHol);
		}
	}

	// hint: use fgetc
	// Please read the document of fgetc carefully, in particular
	// when reaching the end of the file
	
	return true;
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(char * counts, int size)
{
	// print the values in counts in the following format
	// each line has three items:
	// ind, onechar, counts[ind]
	// ind is between 0 and size - 1 (inclusive)
	// onechar is printed if ind is between 'a' and 'z' or
	// 'A' and 'Z'. Otherwise, print space
	// if counts[ind] is zero, do not print
	printf("\n");
	for(int i = 0;i < size;i++){
		printf("%d %d %d\n",i,onechar,counts[i]);
	}

}
#endif
