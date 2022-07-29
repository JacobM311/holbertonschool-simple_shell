#include "main.h"

/**
  * _strncmp - compares two strings up to n characters
  * @s1: string 1
  * @s2: string 2
  * @n: number of characters
  * Return: compared strings
  */

int _strncmp(const char *s1, const char *s2, size_t n)
{
		int diff;
	size_t i;

	diff = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i] || i == n - 1)
		{
			diff = s1[i] - s2[i];
			break;
		}
		i++;
	}

	return (diff);
}
