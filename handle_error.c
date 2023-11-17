#include "shell.h"

/**
 * _printerror - print error
 * @name: string
 * @cmd: command
 * @index: index
*/
void _printerror(char *name, char *cmd, int index)
{
	char *idx, msg[] = ": not found\n";

	idx = _itoa(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(idx), idx = NULL;
}
