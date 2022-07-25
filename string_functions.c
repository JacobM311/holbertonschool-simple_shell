#include "main.h"

/**
  * _strcat - function that concatenates two strings
  * @src: string source
  * @dest: string destination
  * Return: pointer to destination string
  */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int n = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[n] != '\0')
	{
		dest[i] = src[n];
		n++;
		i++;
	}

	dest[i] = '\0';

	return (dest);

}

/**
  * _strcmp - function that compares two strings.
  * @s1: string 1
  * @s2: string 2
  * Return: strings compared
  */

int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}

		s1++;
		s2++;
	}

	return (*s1 - *s2);

}

/**
  * _strlen - function that returns the length of a string.
  * @s: string
  * Return: string length
  */

int _strlen(char *s)
{
	int i = 0;

	while (*s++)

		i++;

	return (i);
}

/**
 * _strcpy - copies string
 * @dest: string destination
 * @src: string source
 * Return: pointer to string destination
 */

char *_strcpy(char *dest, char *src)

{
	char *temp = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
		return (temp);
}

/**
  * _strdup - duplicates a string.
  * @str: pointer to string
  * Return: pointer to string
  */

char *_strdup(char *str)
{
	int i, n;

	char *strcp;

	if (!str)
	{
		return (NULL);
	}

	for (n = 0; str[n] != '\0';)
	{
		n++;
	}

	strcp = malloc(sizeof(char) * n + 1);

	if (!strcp)
	{
		return (NULL);
	}

	for (i = 0; i < n; i++)
	{
		strcp[i] = str[i];
	}

	strcp[n] = str[n];

	return (strcp);
}
