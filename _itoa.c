#include "shell.h"

/**
 * _itoa - turn the character to int
 * @n: int
 * Return: buffer
*/
char *_itoa(int n)
{
	char buf[20];
	int i = 0;

if (n == 0)
{
	buf[i++] = '0';
}
else
{
	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}

}

buf[i] = '\0';
_rev(buf, i);
return (_strdup(buf));
}

/**
 * _rev - reverse string
 * @str: string
 * @l: length
*/
void _rev(char *str, int l)
{
	char tmp;
	int st = 0;
	int end;

	end = l - 1;
	while (st < end)
	{
		tmp = str[st];
		str[st] = str[end];
		str[end] = tmp;
		st++;
		end--;
	}
}
