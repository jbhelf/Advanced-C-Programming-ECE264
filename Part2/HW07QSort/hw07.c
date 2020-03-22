// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
	int size;
	int dummy;

	FILE *fhlr;
	fhlr = fopen(filename, "r");

	if(fhlr == NULL){
		return -1;
	}

	while(fscanf(fhlr, "%d", &dummy) != EOF){
		size++;
	}

	fclose(fhlr);
	return size;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{   
	int rCount = 0;
	int dummy;

	FILE *fhlr;
	fhlr = fopen(filename, "r");

	if(fhlr == NULL){ 
		fclose(fhlr);
		return -1;
	}

	while(fscanf(fhlr, "%d", &dummy) != EOF){
		rCount++;	
	}
	
	if(rCount != size){
		return false;
	}

	fclose(fhlr);
	
	fhlr = fopen(filename, "r");

	if(fhlr == NULL){ 
		fclose(fhlr);
		return -1;
	}

	for(int index = 0;index < rCount;index++){
		fscanf(fhlr, "%d", &intArr[index]);
	}

	fclose(fhlr);
	return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
	return(*(int*)p1 - *(int*)p2);
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{   
	FILE *fhlr;
	fhlr = fopen(filename, "w");

	if(fhlr == NULL){ 
		return false;
	}

	for(int i = 0;i < size;i++){
		fprintf(fhlr, "%d\n", intArr[i]);
	}

	fclose(fhlr);
	return true;
}
#endif
