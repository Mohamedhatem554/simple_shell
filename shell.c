#include "shell.h"

/**
 * main - main function
 * @argc: argc
 * @argv: argv
 * @env: env
 * Return: line
*/
int main(int argc, char **argv, char **env)
{
	char *line = NULL, **cmd = NULL;
	int stat = 0;
	int num = 0;

	(void)argc;
	(void)env;

	while (1)
	{
		line = _getline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		num++;
		cmd = taketoken(line);
		if (!cmd)
		continue;
		free(line), line = NULL;
		stat = _execute(cmd, argv, num);
	}
}
