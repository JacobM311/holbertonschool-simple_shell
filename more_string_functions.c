#include "main.h"

/**
  * _strncmp - compares two strings up to n characters
  * @s1: string 1
  * @s2: string 2
  * @n: number of characters
  * Return: compared strings
  */

int _strncmp(char s1[], char s2[], int n)
{
	int i;

	int strint1, strint2;

	for (i = 0; i < n; i++)
	{
		if (s1[i] == s2[i])
		{
			if (i == (n - 1))
			{
				return (0);
			}
		}

		int strint1 = (int) s1[i];
		int strint2 = (int) s2[i];

		if (strint1 > strint2)
		{
			return (1);
		}
		if (strint2 > strint1)
		{
			return (-1);
		}
	}
}
