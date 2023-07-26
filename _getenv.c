#include "main.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @name: the name of the environment variable.
 *
 * Return: the value of the environment variable.
 */
char *_getenv(const char *name)
{
	char *c_line = NULL;
	char *c_name = NULL;
	unsigned int i = 0;

	if (name == NULL)
		return (NULL);
	while (environ[i])
	{
		c_line = strdup(environ[i]);
		c_name = strtok(c_line, "=");
		if (strcmp(c_name, name) == 0)
		{
			return (strtok(NULL, "\n"));
		}
		i++;
		free(c_line);
	}
	free(c_line);
	return (NULL);
}
