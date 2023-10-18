#include "shell.h"

/**
 * _eputses - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputses(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchars(str[i]);
		i++;
	}
}
