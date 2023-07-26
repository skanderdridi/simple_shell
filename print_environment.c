#include "shell.h"

/**
 * print_environment - function that print environment
 */

void print_environment(void)
{
	char **s = environ;

	for (; *s; s++)
	{
		printf("%s\n", *s);
	}
}

/**
 * if_conditions - function test for built in commands
 * @cmd:  command
 * @line: line
 */
void if_conditions(char **cmd, char *line)
{

	if (strcmp(cmd[0], "exit") == 0)
	{
		free(line);
		if (cmd[1])
			exit(atoi(cmd[1]));
		free_array(cmd);
		exit(0);
	}
}
