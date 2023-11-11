#include "shell.h"
/**
 * print_env - print current environment
 *
 * Return: void
 */

void print_env(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
