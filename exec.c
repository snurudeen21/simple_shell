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
	char *executable_path = NULL;
	struct stat st;

	if (strcspn(args[0], "/") == 0)
	{
		executable_path = args[0];
	}
	else
	executable_path = _pathfinder(args[0]);

	if (stat(executable_path, &st) == 0)
	child_id = fork();

	if (child_id == -1)
	{
		perror("nsh");
		free_buf(args);
		return;
	}
	if (child_id == 0)
	{
		int val = execve(executable_path, args, environ);
		free_buf(args);
		if (val == -1)
		{
			perror("nsh");
			exit(EXIT_FAILURE);
		}
	} else
	{
		do {
			waitpid(child_id, &_stat, WUNTRACED);
		} while (!WIFEXITED(_stat) && !WIFSIGNALED(_stat));
		free_buf(args);
	}
}
