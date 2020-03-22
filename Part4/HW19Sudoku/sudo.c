#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "sudo.h"

#define UNASSIGNED 0
#define N 9

bool solver(int grid[N][N]){
	int row;
	int col;

	if(!FindEmpt(grid, &row, &col)){return true;}

	for(int n = 1;n <=9;n++){
		if(safe(grid, row, col, n)){
			grid[row][col] = n;
			if(solver(grid)){return true;}	
			grid[row][col] = UNASSIGNED;
		}
	}
	return false;
}

bool FindEmpt(int grid[N][N], int *r, int *c){
	for(*r = 0;*r < N;(*r)++){
		for(*c = 0;*c < N;(*c)++){
			if(grid[*r][*c] == UNASSIGNED){
				return true;
			}
		}

	}
	return false;
}

bool UsedInRow(int grid[N][N], int r, int n){
	for(int c = 0;c < N;c++){
		if(grid[r][c] == n){return true;}
	}
	return false;
}

bool UsedInCol(int grid[N][N], int c, int n){
	for(int r = 0;r < N;r++){
		if(grid[r][c] == n){return true;}
	}
	return false;
}

bool UsedInBox(int grid[N][N], int boxStartR, int boxStartC, int n){
	for(int r = 0;r < 3;r++){
		for(int c = 0;c < 3; c++){
			if(grid[r + boxStartR][c + boxStartC] == n){
				return true;
			}
		}
	}
	return false;
}

bool safe(int grid[N][N], int r, int c, int n){
	return(!UsedInRow(grid, r, n) && !UsedInCol(grid, c, n) && !UsedInBox(grid, r - r%3, c - c%3, n) && grid[r][c] == UNASSIGNED);
}

void printer(int grid[N][N]){
	for(int r = 0;r < N;r++){
		for(int c = 0;c < N;c++){
			printf("%d", grid[r][c]);
		}
		printf("\n");
	}
}

