#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"

extern char **environ;
/*functions*/

int _execute(char **cmd, char **arg);
void freearr(char **array);
char *_getline(void);
char *_strdup(const char *string);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char **taketoken(char *str);




#endif
