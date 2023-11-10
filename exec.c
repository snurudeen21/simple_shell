#include "shell.h"
/**
* _exec - execute another program in this current program
* @args: vector array of pointers to command
*
* Return: 0
*/

void _exec(char **args)
{
	pid_t child_id = fork();

	if (child_id == 0)
	{
		execve(args[0], NULL, NULL);
		perror("nsh");
		exit(1);
	}
	else if (child_id > 0)
	{
		int stat;

		do {
			waitpid(child_id, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	else
	{
		perror("nsh");
	}
}
