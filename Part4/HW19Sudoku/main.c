// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "sudo.h"

int main(int argc, char * * argv)
{
	// argv[1]: input file
	if (argc < 2)
	{
		return EXIT_FAILURE;
	}
	
	FILE * fhlr = fopen(argv[1], "r");
	if(fhlr == NULL){
		return EXIT_FAILURE;
	}

	int grid[N][N];	
	int temp;

	for(int row = 0;row < 9;row++){
		for(int col = 0;col < 9;col++){
			temp = fgetc(fhlr);
			if(temp == '\n'){
				temp = fgetc(fhlr);
			}
			if(temp == '-'){
				grid[row][col] = 0;  
			}else{
				grid[row][col] = temp % 48; //ascii value of 0
			}				
		}
	}
	if(solver(grid) == true){
		printer(grid);
	}else{
		fclose(fhlr);
		return EXIT_FAILURE;
	}
	fclose(fhlr);
	return EXIT_SUCCESS;
}
