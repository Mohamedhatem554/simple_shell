#include "shell.h"

/**
 * _execute - execute function
 * @cmd: command
 * @argv: argv
 * @index: index
 * Return: status
*/
int _execute(char **cmd, char **argv, int index)
{
	pid_t cpid;
	int stat;
	char *full;

	full = _getpath(cmd[0]);
	if (!full)
	{
		_printerror(argv[0], cmd[0], index);
		freearr(cmd);
		return (127);
	}
	cpid = fork();
	if (cpid == 0)
	{
		if (execve(full, cmd, environ) == -1)
		{
			freearr(cmd);
			free(full), full = NULL;
		}

	}
	else
	{
		waitpid(cpid, &stat, 0);
		freearr(cmd);
		free(full), full = NULL;
	}
	return (WEXITSTATUS(stat));

}
