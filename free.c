#include "shell.h"

/**
 * freearr - free arrays
 * @array: array
 * Return: nothing
*/
void freearr(char **array)
{
	int n;

	if (!array)
	{
		return;
	}

		for (n = 0; array[n]; n++)
		{
			free(array[n]);
			array[n] = NULL;
		}

		free(array), array = NULL;

}
