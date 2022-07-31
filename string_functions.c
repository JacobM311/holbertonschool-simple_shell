#include "main.h"

/**
  * _strcat - function that concatenates two strings
  * @src: string source
  * @dest: string destination
  * Return: pointer to destination string
  */

char *_strcat(char *dest, char *src)
{
	int i, n, destSize = _strlen(dest), srcSize = _strlen(src);
	char *newStr;

	if(dest == NULL)
		dest = "";
	if(src == NULL)
		src = "";

	newStr = malloc(sizeof(newStr)*(destSize + srcSize + 1));
	if(newStr = NULL)
		return (NULL);

	for (i = 0; i < destSize; i++)
	{
		newStr[i] = dest[i];
	}

	for (n = 0; n < srcSize; n++)
	{
		newStr[i] = src[n];
		i++;
	}

	newStr[i] = '\0';

	return (newStr);

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

	for (i = 0; i != '\0'; i++)
	{
		strcp[i] = str[i];
	}

	strcp[n] = str[n];

	return (strcp);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if strings are equal, or difference if not equal.
 */
int _strcmp(const char *s1, const char *s2)
{
	int diff;
	int i;

	diff = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			break;
		}
		i++;
	}

	return (diff);
}

/**
 * _strlen - gets length of string
 * @str: string
 * Return: length of string
 */

int _strlen(const char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}
