#include "shell.h"
/**
* _exec - execute another program in this current program
* @args: vector array of pointers to command
*
* Return: 0
*/

void _exec(char **args)
{
	pid_t child_id;
	int _stat;
	int i, j;
	i = 0;
	j = 0;
	while (args[i] != NULL)
	{
		i++;
	}
	while (j < i)
	{
		child_id = fork();
		if (child_id == -1)
		{
			perror("nsh");
			free(args[0]);
			return;
		}
		if (child_id == 0)
		{
			if (execve(args[j], args, environ) == -1)
			{
				perror("nsh");
				exit(EXIT_FAILURE);
			}
		} else
		{
			wait(&_stat);
			j++;
		}
	}
}
