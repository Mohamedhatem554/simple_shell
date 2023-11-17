#include "shell.h"

/**
 * taketoken - tokenizer
 * @str: string
 * Return: cmd
*/
char **taketoken(char *str)
{
	char *token = NULL, **cmd = NULL;
	char *tmp = NULL;
	int c = 0, i = 0;

	if (!str)
		return (NULL);
	tmp = _strdup(str);
	token = strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(str);
		free(tmp);
		return (NULL);
	}
	while (token)
	{
		c++;
		token = strtok(NULL, DELIM);
	}
	cmd = malloc(sizeof(char *) * (c + 1));
	if (!cmd)
	{
		free(str);
		free(tmp);
		return (NULL);
	}

	token = strtok(str, DELIM);
	while (token)
	{
		cmd[i] = strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	cmd[i] = NULL;
	free(tmp);
	return (cmd);
}
