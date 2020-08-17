#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int isStable(int grid1[3][3], int gridSchema[3][3]);
void plusOneRound(int grid1[3][3], int i, int j);
void _print_grid(int grid[3][3], int separator);

#endif /* _BINARY_TREES_H_ */
