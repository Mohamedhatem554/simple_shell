#include "shell.h"

/**
 * _getenv - get environ func
 * @cmd: command string
 * Return: env
*/
char *_getenv(char *cmd)
{
	char *env, *token;
	char *val, *tmp;
	int n;

	for (n = 0; environ[n]; n++)
	{
		tmp = _strdup(environ[n]);
		token = strtok(tmp, "=");
		if (_strcmp(token, cmd) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
