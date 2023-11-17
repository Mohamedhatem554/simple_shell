#include "shell.h"

/**
 * _getpath - get path
 * @cmd: command
 * Return: full command
*/
char *_getpath(char *cmd)
{
	char *env, *full_cmd, *dir;
	int i;
	struct stat rr;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &rr) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}

	env = _getenv("PATH");
	if (env == NULL)
		return (NULL);
	dir = strtok(env, ":");
	while (dir != NULL)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, dir);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);
			if (stat(full_cmd, &rr) == 0)
			{
				free(env);
				return (full_cmd);
			}
			free(full_cmd);
			dir = strtok(NULL, ":");
		}
	}
	free(env);
	return (NULL);
}
