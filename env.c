#include "main.h"

/**
  * _getenv - get environment
  * @var: variable
  * Return: NULL
  */

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
