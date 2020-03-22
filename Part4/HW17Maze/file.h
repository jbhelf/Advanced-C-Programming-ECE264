#ifndef MAZE_H
#define MAZE_H
#define STARTSYMBOL	's'
#define BRICKSYMBOL	'b'
#define CORRIDORSYMBOL  ' '
#define INVALIDSYMBOL	'-'

typedef struct
{
	int numRow;
	int numCol;
	int startRow;
	int startCol;
	int curRow;
	int curCol;
	int ** cells;
} Maze;

enum {ORIGIN, EAST, SOUTH, WEST, NORTH};

enum {FORWARD, BACKWARD, DONE};

Maze * makeMaze(char * filename);
void mazeDestroy(Maze * p);
void printer(Maze * p);
#endif
