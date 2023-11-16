#include "shell.h"

/**
 * _getline - readline func
 * Return: line
*/
char *_getline(void)
{
char *line = NULL;
ssize_t i;
size_t l = 0;

if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "$ ", 2);
}
i = getline(&line, &l, stdin);

if (i == -1)
{
free(line);
return (NULL);
}
return (line);
}
