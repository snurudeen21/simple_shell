#include "shell.h"
/**
 * print_env - print current environment
 * @env: Environment Variables
 *
 * Return: void
 */

void print_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
