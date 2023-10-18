#include "shell.h"

/**
 * get_environs - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environs(info_t *info)
{
	if (!info->environs || info->env_changed)
	{
		info->environs = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environs);
}
