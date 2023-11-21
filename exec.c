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

	child_id = fork();
	if (child_id == -1)
	{
		perror("nsh");
		free(args[0]);
		return;
	}
	if (child_id == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		perror("nsh");

		exit(EXIT_FAILURE);
	} else
	{
		do {
			waitpid(child_id, &_stat, WUNTRACED);
		} while (!WIFEXITED(_stat) && !WIFSIGNALED(_stat));
	}
}
