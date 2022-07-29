#include "main.h"

/**
  * execute - forking
  * @command: char
  * Return: int
  */

int execute(char **command)
{
	pid_t status = fork();

	if (status != 0)
	{
		wait(NULL);
		return (0);
	}
	if (status == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			perror("Error");
			return (-1);
		}
	}

	return (0);
}

/**
  * make_av - make array
  * @str: string
  * Return: char
  */

char **make_av(char *str)
{
	char *buffer = _strdup(str);
	char *argument;
	char prev = '0';
	int i = 0, numArgs = 0;

	while (buffer[i])
	{
		if (buffer[i] == ' ' && prev != ' ')
			numArgs++;
		prev = buffer[i];
		i++;
	}

	av = malloc(sizeof(*av) * (numArgs + 2));

	argument = strtok(buffer, " \n");
	av[0] = argument;

	i = 1;
	while (argument != NULL)
	{
		argument = strtok(NULL, " \n");
		av[i] = argument;
		i++;
	}

	av[i] = NULL;
	return (av);
}
