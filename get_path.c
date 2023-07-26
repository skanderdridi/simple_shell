#include "shell.h"

/**
 * get_path - Returns the value of the PATH enviroment variable.
 *
 * Return: Pointer to the value of $PATH.
 */
char *get_path(void)
{
	return (print_environment("PATH"));
}
