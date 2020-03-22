#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "maze.h"

void deleteMaze(Maze * pos){
	if(pos == NULL){
		return;
	}
	if(pos->north != NULL){deleteMaze(pos->north);}
	if(pos->south != NULL){deleteMaze(pos->south);}
	if(pos->east != NULL){deleteMaze(pos->east);}
	if(pos->west != NULL){deleteMaze(pos->west);}
	free(pos);
}

void freeMaze(Start * sPos){
	if(sPos == NULL){
		return;
	}

	Maze * leftCol = NULL; //items in far left column
	leftCol = sPos->root;

	while(leftCol->north != NULL && leftCol->east != NULL){
		if(leftCol->north != NULL){
			leftCol = leftCol->north;
		}
		if(leftCol->east != NULL){
			leftCol = leftCol->east;
		}
	}

	deleteMaze(leftCol);
	free(sPos);
}

void printRow(Maze * leftCol){
	Maze * q = NULL;
	q = leftCol;

	printf("\n");

	while(q != NULL){
		printf("%d ", q->step);
		q = q->west;
	}
}

void printer(Start * sPos){
	Maze * leftCol = NULL; //items in far left column
	leftCol = sPos->root;

	while(leftCol->north != NULL && leftCol->east != NULL){
		if(leftCol->north != NULL){
			leftCol = leftCol->north;
		}
		if(leftCol->east != NULL){
			leftCol = leftCol->east;
		}
	}

	while(leftCol != NULL){
		printRow(leftCol);
		leftCol = leftCol->south;
	}	
}

Maze * makeSpace(Maze * p, int w, int max){
	int h = max / w;

	p->south = malloc(sizeof(Maze));
	p->south->north = p;

	for(int j = 1;j < h; j++){
		for(int i = 1;i <= w;i++){
			p->west = malloc(sizeof(Maze));
			p->west->east = p;
			p = p->west;

			if((j + 1) < h){
				p->south = malloc(sizeof(Maze));
				p->south->north = p;

				p->south->east = p->east->south;
				p->east->south->west = p->south;

				j++; //another row modified
			}
		}
		for(int i = w;i >= 1;i--){
			p = p->east;
		}//returns back to left column
	}

	if(p->east == NULL){
		for(int i = w;i >= 1;i--){
			p = p->east;
		}
	}
	for(int i = h;i <= 1;i--){
		p = p->north;
	}

	return p;
}

Maze * makeMaze(int w, int max, char * filename){
	Maze * start = NULL;
	start = malloc(sizeof(Maze));

	Maze * p = NULL;
	p = malloc(sizeof(Maze));

	p = makeSpace(p, w, max);

	int temp = 0; //counts the amount of variables copied

	FILE * fhlr = fopen(filename, "r");
	if(fhlr == NULL){
		return false;
	}

	char num = fgetc(fhlr);

	while(num != -1){
		if(num == 'b'){
			p->step = -1;
		}else if(num == 's'){
			p->step = 0;
			start = p;
		}else{
			p->step = max;
		}

		temp++;
		if(temp == (w - 1)){
			while(temp != 0){
				p = p->east; 
				temp--;
			}
			p = p->south;
		}else{
			p = p->west;
		}
		num = fgetc(fhlr);
	}

	fclose(fhlr);

	return(start);
}

Start * convert(char * filename){

	FILE * fhlr = fopen(filename, "r");
	if(fhlr == NULL){
		return false;
	}

	int width = 0;
	int height = 0;
	char * num = malloc(sizeof(char*));
	*num = fgetc(fhlr);

	while(*num != EOF){
		if(height == 0 && *num != '\n'){ //while on 1st row
			width++;
		}
		if(*num == '\n'){
			height++;
		}
		*num = fgetc(fhlr);
	}

	fclose(fhlr);

	makeMaze(width, (width * height), filename);

	Start * sPos = NULL; //starting position
	sPos = malloc(sizeof(Start));
	//make sure when coming across s to assign to 0, AND assign sPos

	free(fhlr);
	return sPos;
}

void helper(int dist, Maze * position){	

	if(position->north->step != -1 && position->north != NULL){
		helper(dist + 1, position->north);
	}
	if(position->south->step != -1 && position->south != NULL){
		helper(dist + 1, position->south);
	}
	if(position->east->step != -1 && position->east != NULL){
		helper(dist + 1, position->east);
	}
	if(position->west->step != -1 && position->west != NULL){
		helper(dist + 1, position->west);
	}

	if(position->step > dist){
		position->step = dist;
	}	
}

void stepCounter(Start * sPos){
	Maze * position = NULL;
	position = malloc(sizeof(Maze));
	position = sPos->root;

	helper(0, position);
}
