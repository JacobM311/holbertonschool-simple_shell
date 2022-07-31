#include "main.h"

/**
  * main - main shell function
  * Return: int
  */

int main(void)
{
	char *buffer = NULL;
	char **envp = environ;
	size_t size = 0;
	int i, status = EXIT_SUCCESS;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		if (getline(&buffer, &size, stdin) == EOF)
			break;
		if (strcmp(buffer, "exit\n") == 0)
			 break;
		if (strcmp(buffer, "env\n") == 0)
		{
			for (i = 0; envp[i]; i++)
				printf("%s\n", envp[i]);
		free(buffer);
		buffer = NULL;
		continue;
		}
		for (i = 0; buffer[i] != '\n'; i++)
		{
			if (buffer[i] != ' ')
			{
				status = make_av(buffer, status);
				break;
			}
		}
	}
	if(buffer)
		free(buffer);
	return (status);
}

/**
  * make_av - make array
  * @buffer: buffer
  * @status: status
  * Return: int
  */

int make_av(char *buffer, int status)
{
	char *av[32], *argument, *command;
	int i = 0;

	/*create argument variables from buffer*/
	argument = strtok(buffer, " \n");

	for (i = 0; argument != NULL; i++)
	{
		av[i] = argument;
		argument = strtok(NULL, " \n");
	}
	av[i] = NULL;

	/*pass argument variable to function to concat path to file*/
	command = create_path(av[0]);
	if (strcmp(command, av[0]) != 0)
	{
		av[0] = command;
	}
	/*if file exists and is executable, it is passed to command to execute*/
	status = execute(av, status);
return (status);
}

/**
  * create_path - create path
  * @file: file
  * Return: command
  */

char *create_path(char *file)
{
	char *command = NULL, *path, *temp, *path_tok;
	struct stat st;

	/*check to see if file path was given*/
	if (stat(file, &st) == 0)
	{
		if (access(file, X_OK) == 0)
			return (file);
	}
	/*get path then pass fisrt path token to loop to check if file path exists*/
	path = _getenv("PATH");
	path_tok = strtok(path, ":");
	while (path_tok)
	{
		path_tok = strdup(path_tok);
		temp = strcat(path_tok, "/");
		command = strcat(temp, file);
		if (stat(command, &st) == 0)
		{
			if (access(command, X_OK) == 0)
			{
				return (command);
			}
		}
		path_tok = strtok(NULL, ":\n");
	}
	perror("Error");
		return (NULL);
	free(path);
	return (command);
}

/**
  * execute - execute command
  * @command: command
  * @status: status
  * Return: status
  */

int execute(char **command, int status)
{
	pid_t check = fork();

	if (check != 0)
	{
		wait(&status);
		status = WEXITSTATUS(status);
	}
	if (check == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		perror("Error");
	}
	return (status);
}
