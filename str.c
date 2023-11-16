#include "shell.h"


/**
 * _strdup - duplicate strings
 * @string: string
 * Return: string
*/
char *_strdup(const char *string)
{
	char *ptr;
	int i, l = 0;

	if (string == NULL)
	return (NULL);
	while (*string != '\0')
	{
		l++;
		string++;
	}
	string = string - l;

	ptr = malloc(sizeof(char) * (l + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= l; i++)
	{
		ptr[i] = string[i];
	}
	return (ptr);
}


/**
 * _strcmp - entry point
 * @s1: char
 * @s2: char
 * Return: (s1 - s2) or (0)
*/
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);

}



/**
 * _strlen - entry point
 * @s: character to be counted
 * Return: l
*/
int _strlen(char *s)
{
	int l;

	for (l = 0; *s != '\0'; s++)
	{
		l++;
	}
	return (l);
}



/**
 * _strcat - entry point
 * @dest: char
 * @src: source
 * Return: dest
*/
char *_strcat(char *dest, char *src)
{
	int destlen = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
	dest[destlen + i] = src[i];
	dest[destlen + i] = '\0';

	return (dest);
}



/**
 * _strcpy - entry point
 * @dest: char
 * @src: source
 * Return: dest if success
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	while (src[i] != '\0')
	{

		dest[i] = src[i];
		i++;

	}
	dest[i] = src[i];

	return (dest);
}
