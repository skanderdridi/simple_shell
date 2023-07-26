#include "shell.h"

/**
 * exec_command - function that executes a command
 * @cmd: the command to be executed
 */

void exec_command(char **cmd)
{
	pid_t pid = 0;
	int i = 0;

	if (cmd)
	{
		pid = fork();
		if (pid == -1)
			printf("Error in Fork\n");
		else if (pid > 0)
			/* Block parent process until the child process terminate */
			waitpid(pid, &i, 0);

		else if (pid == 0)
		{
			if (execve(cmd[0], cmd, environ) == -1)
				printf("%s: not found", cmd[0]);
			else
				execve(cmd[0], cmd, environ);
		}
	}
}

/**
 * sigintHandler - function that handle Control-C signal
 * @sig_num: sig_num
 */

void sigintHandler(__attribute__((unused)) int sig_num)
{
	signal(SIGINT, sigintHandler);
	printf("\n");
	write(STDOUT_FILENO, "$ ", 2);
}
