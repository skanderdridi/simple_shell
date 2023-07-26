#include "shell.h"
#include <stdio.h>
/**
 * get_path - function that gets the path
 * @cmd: the command line
 */

void get_path(char **cmd)
{
	int i;
	char **tok = NULL, *path = strdup(getenv("PATH")), *tmp = NULL;

	tok = str_split(path, ":");
	free(path);
	path = NULL;
	for (i = 0; tok[i]; i++)
	{
		tmp = calloc(sizeof(char), (strlen(tok[i]) + 1 + strlen(cmd[0]) + 1));
		strcat(tmp, tok[i]);
		strcat(tmp, "/");
		strcat(tmp, cmd[0]);

		if (access(tmp, F_OK) == 0)
			break;
		free(tmp);
		tmp = NULL;
	}
	free_array(tok);
	free(cmd[0]);
	cmd[0] = tmp;
}
