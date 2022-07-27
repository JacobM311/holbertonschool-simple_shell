#include "main.h"

/**
*stringlength - gets the length of a string
*@str: the string to get length of
*Return: length of string
*/

int stringlength(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
