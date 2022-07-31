#include "main.h"

int printenv(int status)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
	return (status);
}

char *_getenv(char *var)
{
	int i, len = strlen(var);

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], var, len) == 0)
		{
			return (strdup(environ[i] + len + 1));
		}
	}
	return (NULL);
}
