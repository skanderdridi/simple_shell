#include "shell.h"

/**
 * free_array - function that free an array
 * @array: array to be freeded
 */

void free_array(char **array)
{
	int i;

	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}

/**
 * loop - function loop REPL
 * @input:  return value of isatty 0 or 1
 */
void loop(int input)
{
	char *line = NULL, **cmd = NULL;
	size_t size = 0;
	int lengh;
	struct stat state;

	while (1)
	{
		if (input)
			write(STDOUT_FILENO, "$ ", 2);
		lengh = getline(&line, &size, stdin);
		if (lengh == EOF)
		{
			free(line);
			exit(0);
		}
		if (strcmp(line, "\n") == 0)
			continue;
		cmd = str_split(line, " \t\r\n");
		if_conditions(cmd, line);
		if (strcmp(cmd[0], "env") == 0)
		{
			print_environment();
			free_array(cmd);
			continue;
		}
		if (stat(cmd[0], &state) != 0)
			get_path(cmd);
		if (cmd[0] == NULL)
		{
			printf("Command not found\n");
			free(line);
			line = NULL;
			free_array(cmd);
			cmd = NULL;
			continue;
		}
		exec_command(cmd);
		free_array(cmd);
	}
	free(line);
}

/**
 * main - the entry point
 * Return: 0
 */

int main(void)
{
	signal(SIGINT, sigintHandler);
	loop(isatty(STDIN_FILENO));

	return (0);
}
