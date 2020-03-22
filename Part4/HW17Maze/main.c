#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "maze.h"

int main(int argc, char * * argv)
{
	if(argc < 2){
		return EXIT_FAILURE;
	}

	Start * sPos = convert(argv[1]);
	
	stepCounter(sPos);

	printer(sPos);

	freeMaze(sPos);
	return EXIT_SUCCESS;	
}
