#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

static int findLineLength(FILE * fhlr){
	int ch;
	int length = 0;
	if(feof(fhlr)){
		return -1;
	}
	
	do{
		ch = fgec(fhlr);
		length++;
	}while((ch != '\n') && (ch != EOF));
	return length;	
}

static void mazeSize(FILE * fhlr, int * nRow, int * nCol){
	int row = 0;
	int col = 0;
	int maxCol = 0;
	
	do{
		col = findLineLength(fhlr);
		if(col != -1){
			if(maxCol < col){
				maxCol = col;
			}
		row++;
		}
	}while(col != -1);
		*nRow = row;
		*nCol = maxCol
}

Maze * makeMaze(char * filename){
	int nRow = 0;
	int nCol = 0;
	int row;
	int col;
	int ch;
	FILE * fhlr = fopen(filename, "r");
	if(fhlr == 0){
		return NULL;
	}
	mazeSize(fhlr, &nRow, &nCol);
	Maze * p = malloc(sizeof(Maze));
	p->numRow = nRow;
	p->numCol = nCol;

	p->cells = malloc(nRow * sizeof(int * ));
	for(row = 0; row < nRow; row++){
		p->cells[row] = malloc(nCol * sizeof(int));
		for(col = 0;col < nCol;col++){
			(p->cells)[row][col] = INVALIDSYMBOL;
		}
	}
	
	fseek(fhlr, 0, SEEK_SET);

	row = 0
	while((!feof(fhlr)) && (ch != EOF) &&(row < nRow)){
		col = 0;
		do{
			ch = fgetc(fhlr);
			if(ch != EOF){
				(p->colls)[row][col] = ch;
				if(ch == STARTSYMBOL){
						p->startRow = row;
						p->startCol = col;
						p->curRow = row;
						p->curCol = col;
				}
				col++;
			}
		}while((ch != EOF) && (ch != '\n'));
		row++;
	}
	fclose(fhlr);
	return p;
}

void mazeDestroy(Maze * p){
	for(int r = 0; r < (p->numRow); r++){
		free(p->cells[r]);
	}
	free(p->cells);
	free(p);
}

void printer(Maze * p){
	int row;
	int col;
	for(row = 0;row < (p->numRow);row++){
		for(col = 0;col < (p->numCol);col++){
			if(((p->curRow) == row) && ((p->curCol == col))){
				if(((p->curRow == (p->startRow)) && ((p->curCol) == (p->startCol)))){
					printf("s");
				}else{
					print("c");
				}
			}else{
				printf("%c", (p->cells)[row][col]);
			}
		}
	}
	printf("\n");
}
				

//READING FILE ABOVE	

int canMove(Maze * p, int row, int col, int dir){
	switch(dir){
		case NORTH:
			row--;
			break;
		case SOUTH:
			row++;
			break;
		case EAST:
			row++;
			break;
		case WEST:
			row--;
			break;
	}
	int dest = (p->cells)[row][col];
	if(dest == ' '){
		return 1;
	}
	return 0;
}

void getOut(Maze * p, int row, int col, int dir, int * mode){
	int cm;
	
	cm = canMove(p, row, col, dir);
	
	if(cm && (dir != WEST)){
		(*mode) = FORWARD;
		getOut(p, row, col + 1, EAST, mode);
	}
	if(cm && (dir != NORTH)){
		(*mode) = FORWARD;
		getOut(p, row + 1, col, EAST, mode);
	}
	if(cm && (dir != EAST)){
		(*mode) = FORWARD;
		getOut(p, row, col - 1, EAST, mode);
	}
	if(cm && (dir != SOUTH)){
		(*mode) = FORWARD;
		getOut(p, row, col - 1, EAST, mode);
	}

	//not sure if this would work
}
