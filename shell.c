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

/**
  * _path - path
  * @str: string
  * Return: char
  */

char *_path(char *str)
{
	char *exec;
	char *path;
	char **path_array;
	int i = 0;
	char *final_path;

	exec = _strcat("/", str);
	path = _getenv("PATH");
	path_array = create_path(path);

	while (path_array[i])
	{
		path_array[i] = _strcat(path_array[i], exec);
		i++;
	}

	final_path = _stat(path_array);
	if (final_path)
		return (final_path);

	return (NULL);
}

/**
  * create_path - path
  * @command: yes
  * Return: char
  */

char **create_path(char *command)
{
	char *buffer = _strdup(command);
	char *argument;
	int i = 0, elements = 0;

	while (buffer[i])
	{
		if (buffer[i] == ':')
			elements++;
		i++;
	}

	path_av = malloc(sizeof(*path_av) * (elements + 2));

	argument = strtok(buffer, ":");
	path_av[0] = argument;

	i = 1;
	while (argument != NULL)
	{
		argument = strtok(NULL, ":");
		av[i] = argument;
		i++;
	}
	return (path_av);
}

/**
  * _stat - stat
  * @var: yes
  * Return: char
  */

char *_stat(char **var)
{
	unsigned int i;
	struct stat st;

	i = 0;
	while (var[i])
	{
		if (stat(var[i], &st) == 0)
			return (var[i]);
		i++;
	}
	return (NULL);
}
