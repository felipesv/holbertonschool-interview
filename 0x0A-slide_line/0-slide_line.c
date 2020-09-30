#include "slide_line.h"
/**
 * slide_line - function that slides
 * @line: array of integers
 * @size: length of array
 * @direction: direction of merge
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line)
		return (0);
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}
	else
	{
		slide_right(line, size);
		return (1);
	}
}


/**
 * slide_left - slides integers left
 * @line: array
 * @size: length
 */
void slide_left(int *line, size_t size)
{
	size_t i, j;
	int current, flag = 0;

	for (i = 0; i < size; ++i)
	{
		if (line[i] > 0 && !flag)
		{
			current = i;
			flag = 1;
			continue;
		}
		if (line[i] == line[current] && flag)
		{
			line[current] *= 2;
			current += 1;
			line[i] = 0;
			flag = 0;
		}
	}
	for (i = 0, j = 0; i < size && j < size; ++i)
	{
		while (line[j] == 0 && j < size && j + 1 < size)
			j++;
		if (line[i] == 0)
			swap(&line[j], &line[i]);
		j++;
	}
}

/**
 * slide_right - slides integers right
 * @line: array
 * @size: length
 */
void slide_right(int *line, size_t size)
{
	size_t i, j;
	int current, flag = 0;

	for (i = size - 1; (int)i >= 0; --i)
	{
		if (line[i] > 0 && !flag)
		{
			current = i;
			flag = 1;
			continue;
		}
		if (line[i] == line[current] && flag)
		{
			line[current] *= 2;
			line[i] = 0;
			flag = 0;
		}
		else if (line[i] > 0)
		{
			current = i;
			flag = 1;
		}
	}
	for (i = size - 1, j = size - 1; (int)i >= 0 && (int)j >= 0; --i)
	{
		while (line[j] == 0 && j > 0)
			j--;
		if (line[i] == 0)
			swap(&line[j], &line[i]);
		j--;
	}
}
/**
 * swap - swaps two integers
 * @a: number 1
 * @b: number 2
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
