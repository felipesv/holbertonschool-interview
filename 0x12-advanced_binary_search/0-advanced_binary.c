#include "search_algos.h"
/**
 * print_array - print the message
 * @array: array to print
 * @from: index to start print
 * @to: index to end print
 *
 * Return: is a void
 */
void print_array(int *array, int from, int to)
{
	int cnt = 0;
	char comma = '\0';

	printf("Searching in array:");
	for (cnt = from; cnt <= to; cnt++)
	{
		printf("%c %i", comma, array[cnt]);
		comma = ',';
	}
	printf("\n");
}
/**
 * recursion_binary - print the message
 * @array: array to find
 * @from: index to start search
 * @to: index to end search
 * @value: value to find
 *
 * Return: index
 */
int recursion_binary(int *array, int from, int to, int value)
{
	int middle = ((to - from) / 2) + from;

	if (from == to)
	{
		if (array[from] == value)
			return (from);
		print_array(array, from, to);
		return (-1);
	}

	print_array(array, from, to);
	if (array[middle] >= value)
		return (recursion_binary(array, from, middle, value));
	else
		return (recursion_binary(array, middle + 1, to, value));
}
/**
 * advanced_binary - print the message
 * @array: array to find
 * @size: array length
 * @value: value to find
 *
 * Return: index
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (recursion_binary(array, 0, (int) size - 1, value));
}

