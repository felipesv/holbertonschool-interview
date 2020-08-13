#include "sandpiles.h"
/**
 * sandpiles_sum - sum two sandpiles
 *
 * @grid1: sandpile1
 * @grid2: sandpile2
 *
 * Return: nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;
	int grid3[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}

	while (isStable(grid1, grid3) != 0)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid3[i][j] == 1)
					plusOneRound(grid1, i, j);
			}
		}
	}
}
/**
 * isStable - verify if is stable
 *
 * @grid1: sandpile1 to verify
 * @grid3: sandpile schema
 *
 * Return: 0 is stable, otherwise not is stable
 */
int isStable(int grid1[3][3], int grid3[3][3])
{
	int i = 0, j = 0, cnt = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				cnt++;
				grid3[i][j] = 1;
			}
			else
				grid3[i][j] = 0;
		}
	}

	if (cnt != 0)
		_print_grid(grid1, 1);

	return (cnt);
}
/**
 * plusOneRound - all the operation
 *
 * @grid1: sandpile1
 * @i: row
 * @j: column
 *
 * Return: nothing
 */
void plusOneRound(int grid1[3][3], int i, int j)
{
	int topi = i - 1, lefti = i, righti = i, bottomi = i + 1;
	int topj = j, leftj = j - 1, rightj = j + 1, bottomj = j;

	grid1[i][j] -= 4;
	if (topi >= 0 && topi < 3 && topj >= 0 && topj < 3)
		grid1[topi][topj] += 1;
	if (lefti >= 0 && lefti < 3 && leftj >= 0 && leftj < 3)
		grid1[lefti][leftj] += 1;
	if (righti >= 0 && righti < 3 && rightj >= 0 && rightj < 3)
		grid1[righti][rightj] += 1;
	if (bottomi >= 0 && bottomi < 3 && bottomj >= 0 && bottomj < 3)
		grid1[bottomi][bottomj] += 1;
}
/**
 * _print_grid - print the grid
 *
 * @grid1: sandpile1
 * @separator: separator
 *
 * Return: nothing
 */
void _print_grid(int grid1[3][3], int separator)
{
	int i, j;

	if (separator)
		printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid1[i][j]);
		}
		printf("\n");
	}
}
