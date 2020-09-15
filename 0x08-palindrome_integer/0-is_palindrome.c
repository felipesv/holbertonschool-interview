#include "palindrome.h"
/**
 * is_palindrome - know if a number is a palindrome
 *
 * @n: numbre
 *
 * Return: 1: palindrome - 0: not a palindrome
 */
int is_palindrome(unsigned long n)
{
	int cnt1 = 0, cnt2 = 0;
	unsigned long array[1024];
	unsigned long new_n = n;

	while (new_n != 0)
	{
		array[cnt1++] = new_n % 10;
		new_n = new_n / 10;
	}

	cnt1--;
	for ( ; cnt1 > cnt2; cnt1--, cnt2++)
	{
		if (array[cnt1] != array[cnt2])
			return (0);
	}

	return (1);
}
