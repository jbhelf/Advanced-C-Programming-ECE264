// ***
// *** You must modify this file
// ***

#ifndef MEMORY_H
#define MEMORY_H
#include <stdbool.h>

typedef struct data
{
	// create the necessary attributes
	int val;
	struct data * next;
} Memory;

bool createMemory(Memory * * mem, int size);
void destroyMemory(Memory * mem);
int allocateMemory(Memory * mem, int size);
bool saveOccupancy(Memory * mem, const char * filename);
void freeMemory(Memory * mem, int starting);
#endif
