#include "shell.h"
/**
 * print_env - print current environment
 *
 * Return: void
 */

void print_env(void)
{
	int i = 0;
	char *env = NULL;

	while ((env = environ[i]) != NULL)
	{
		printf("%s\n", env);
		i++;
	}
}
