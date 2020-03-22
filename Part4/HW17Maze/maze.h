#ifndef MAZE_H
#define TREE_H

typedef struct mazepos
{
	int step;
	struct mazepos * north;
	struct mazepos * south;
	struct mazepos * east;
	struct mazepos * west;
} Maze;

typedef struct mazeroot
{
	Maze * root;	
} Start;

void printer(Start * sPos);
void freeMaze(Start * sPos);
Start * convert(char * filename);
void stepCounter(Start * sPos);
#endif
