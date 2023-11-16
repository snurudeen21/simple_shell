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
	char *executable_path;
	struct stat st;

	if (strcspn(args[0], "/") == 0)
	{
		executable_path = args[0];
		if (stat(executable_path, &st) == -1)
		executable_path = NULL;
	}
	else
	executable_path = _pathfinder(args[0]);

	if (executable_path == NULL)
	{
		free(executable_path);
		return;
	}

	child_id = fork();
	if (child_id == -1)
	{
		perror("nsh");
		free(executable_path);
		return;
	}
	if (child_id == 0)
	{
		if (execve(executable_path, args, environ) == -1)
		perror("nsh");

		exit(EXIT_FAILURE);
	} else
	{
		do {
			waitpid(child_id, &_stat, WUNTRACED);
		} while (!WIFEXITED(_stat) && !WIFSIGNALED(_stat));
	}

	free(executable_path);
}
