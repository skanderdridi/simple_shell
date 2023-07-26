#include "shell.h"

/**
 * checkbin - checks if the input is a built in and executes it
 *
 * @input: input
 * @tokens: tokens
 * Return: 0 if succed, -1 if built in doesn´t exist
 */

int checkbin(char *input, char **tokens)
{
	int a, b;
	built_in bi[] = {
		{fenv, "env"},
		{fexit, "exit"},
		{NULL, NULL}
	};

	for (a = 0; bi[a].name != NULL; a++)
	{
		if (_strcmp(bi[a].name, input) == 0)
		{
			free(tokens), free(input);
			b = bi[a].func();
			return (b);
		}
	}
	return (-1);
}

/**
 * fenv - prints enviromental variables
 *
 * Return: 0
 */

int fenv(void)
{
	int a;
	size_t b = 0;

	for (a = 0; environ[a] != NULL; a++)
	{
		b = _strlen(environ[a]);
		write(1, environ[a], b + 1);
		write(1, "\n", 2);
	}
	return (0);
}

/**
 * fexit - exits the shell
 *
 * Return: 1
 */

int fexit(char **args, char **front)
{
	int i, len_of_int = 10;
	unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			i = 1;
			len_of_int++;
		}
		for (; args[0][i]; i++)
		{
			if (i <= len_of_int && args[0][i] >= '0' && args[0][i] <= '9')
				num = (num * 10) + (args[0][i] - '0');
			else
				return (create_error(--args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (num > max - 1)
		return (create_error(--args, 2));
	args -= 1;
	free_args(args, front);
	free_env();
	free_alias_list(aliases);
	exit(num);
}
