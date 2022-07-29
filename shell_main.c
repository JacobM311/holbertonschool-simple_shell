#include "main.h"

/**
  * main - main shell function
  * Return: int
  */

int main(void)
{
	char *buffer = NULL;
	char **command;
	size_t size = 0;
	int i = 0;

	while (1)
	{
		write(1, "$ ", 2);
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
	}
	free(buffer);
	free(av);
	return (0);
}
