#include "shell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * _path - is path?
 * @path: path
 *
 * Return: 1 (not absolute) 0 (absolute)
 **/
char *path(char *filename)
{
	char *PATH = getenv("PATH");
	char *cpy = _strdup(PATH), *concatenated = NULL;
	char *token = NULL, *absolute = NULL;
	struct stat st;

	token = _strtok(cpy, ':');
	concatenated = str_concat("/", filename);
	while (token != NULL)
	{
		absolute = str_concat(token, concatenated);
		if (stat(absolute, &st) == 0)
		{
			free(PATH);
			free(cpy);
			free(concatenated);
			return (absolute);
		}
		token = _strtok(NULL, ':');
		free(absolute);
	}
	free(PATH);
	free(concatenated);
	free(cpy);
	return (NULL);
}
