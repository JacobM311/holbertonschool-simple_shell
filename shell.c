#include "main.h"

char **av;
char **path_av;
char *_path(char *str);
char **create_path(char *command);
char *_stat(char **var);

int main(void)
{
	char *buffer = NULL;
	char **command;
	char *path_exec;
	size_t size = 0;
	int i = 0;

	while(1)
	{
		write (1, "$ ", 2);
		getline(&buffer, &size, stdin);
		if (buffer[0] == '/' || '.')
		{
			if (_strcmp(buffer, "exit\n") == 0)
				break;
			if (_strcmp(buffer, "env\n") == 0)
				for (i = 0; environ[i]; i++)
				{
					_printf("%s\n", environ[i]);
				}
			else
			{
				command = make_av(buffer);
				if (execute(command) == -1)
					break;
			}
		}
		else
		{
			command = make_av(buffer);
			path_exec = _path(command[0]);
			if (execute(path_exec) == -1)
				break;
			
		}
	}
	free(buffer);
	free(av);
	return (0);
}

int execute(char **command)
{
	pid_t status = fork();

	if (status != 0)
	{
		wait(NULL);
		return(0);
	}
	if (status == 0)
	{
		if (execve(command[0], command, NULL) == -1);
		perror("Error");
		return (-1);	
	}

	return (0);
}

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

char *_path(char *str)
{
	char *exec;
	char *path;
	char **path_array;
	int i = 0;
	char *final_path;

	exec = strcat("/", str);
	path = _getenv("PATH");
	path_array = create_path(path);

	while (path_array[i])
	{
		path_array[i] = strcat(path_array[i], exec);
		i++;
	}

	final_path = _stat(path_array);
	if (final_path);
	return (final_path);

	return (NULL);
}

char **create_path(char *command)
{
	char *buffer = strdup(command);
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
