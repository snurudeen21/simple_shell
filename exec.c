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
	char *executable_path = _pathfinder(args[0]);

	if (executable_path == NULL) {
		free(args[0]);
		free(args);
		return;
	}

	child_id = fork();
	if (child_id == -1) {
		perror("nsh");
		free(executable_path);
		return;
	}

	if (child_id == 0) {
		if (execve(executable_path, args, NULL) == -1) {
			perror("nsh");
		}
		exit(EXIT_FAILURE);
	} else {
		do {
			waitpid(child_id, &_stat, WUNTRACED);
		} while (!WIFEXITED(_stat) && !WIFSIGNALED(_stat));
	}

	free(executable_path);
}
