#include "menger.h"
/**
 * menger - print a menger sponge
 *
 * @level: Menger sponge level
 *
 * Return: is a void
 */
void menger(int level)
{
	int size = (int) pow(3, (double) level);
	int cnt1 = 0, cnt2 = 0, _cnt1 = 0, _cnt2 = 0;
	char character = '#';

	if (level < 0)
		return;

	for (cnt1 = 0; cnt1 < size; ++cnt1)
	{
		for (cnt2 = 0; cnt2 < size; ++cnt2)
		{
			_cnt1 = cnt1;
			_cnt2 = cnt2;
			character = '#';

			while (_cnt1 && _cnt2)
			{
				if (_cnt1 % 3 == 1 && _cnt2 % 3 == 1)
				{
					character = ' ';
					break;
				}

				_cnt1 /= 3;
				_cnt2 /= 3;
			}

			printf("%c", character);
		}
		printf("\n");
	}
}
