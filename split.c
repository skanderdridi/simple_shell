#include "shell.h"

/**
 * str_split - function that parse a line of string
 * @line:  line to parsed
 * @delim: delimeter to parse with
 * Return: array of parsed elements
 */

char **str_split(char *line, char *delim)
{
	char *ptr = NULL, **cmd = NULL;
	size_t i = 0;

	ptr = strtok(line, delim);
	while (ptr)
	{
		cmd = realloc(cmd, ((i + 1) * sizeof(char *)));
		cmd[i] = strdup(ptr);
		ptr = strtok(NULL, delim);
		i++;
	}

	cmd = realloc(cmd, ((i + 1) * sizeof(char *)));
	cmd[i] = NULL;

	return (cmd);
}
