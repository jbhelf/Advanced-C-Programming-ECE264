#ifndef TREE_H
#define TREE_H

#define N 9

bool solver(int grid[N][N]);
//bool UsedInCol(int grid[N][N],int r, int n);
bool UsedInCol(int grid[N][N],int c, int n);
bool UsedInBox(int grid[N][N], int boxStartR, int boxStartC, int n);
bool safe(int grid[N][N], int r, int c, int n);
void printer(int grid[N][N]);
bool FindEmpt(int grid[N][N], int *r, int *c);

#endif
