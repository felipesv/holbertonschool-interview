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
	int mid;

	if (from > to)
		return (-1);

	print_array(array, from, to);

	if (from == to && array[to] == value)
		return (to);

	if (from == to && array[to] != value)
		return (-1);

	mid = from + (to - from) / 2;

	if ((mid == from || value != array[mid - 1]) && array[mid] == value)
		return (mid);

	if (array[mid] >= value)
		return (recursion_binary(array, from, mid, value));
	return (recursion_binary(array, mid + 1, to, value));
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

	if (!array || size == 0)
		return (-1);

	return (recursion_binary(array, 0, size - 1, value));
}
