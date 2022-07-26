#include "main.h"

char *_getenv(const char *var)
{
	int i = 0, match, len = strlen(var);

	while (environ[i])
	{
		match = strncmp(environ[i], var, len);
		if (match == 0)
			return (environ[i] + len + 1);
		i++;
	}
	return (NULL);
}
