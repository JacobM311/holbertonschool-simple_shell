#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **str_tok(char *str)
{
	static char *tokens[5];
	int i = 0;
	char *buffer = strdup(str);
	char *token = strtok(buffer, " ");
	int len = 0, numTokens = 0;

	while (buffer[len])
	{
		if (buffer[len] == ' ')
		{
			numTokens++;
		}

		len++;
	}

	tokens[i] = token;
	i++;
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		tokens[i] = token;
		i++;
	}

	return (tokens);
}

int main(void)
{
	char **array;
	int i = 0;

	array = str_tok("Hello World. You Suck.");

	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}
