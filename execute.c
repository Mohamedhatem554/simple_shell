#include "shell.h"

/**
 * _execute - execute function
 * @cmd: command
 * @argv: argv
 * Return: status
*/
int _execute(char **cmd, char **argv)
{
	pid_t cpid;
	int stat;

	cpid = fork();
	if (cpid == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			freearr(cmd);
			exit(0);
		}

	}
	else
	{
		waitpid(cpid, &stat, 0);
		freearr(cmd);
	}
	return (WEXITSTATUS(stat));

}
