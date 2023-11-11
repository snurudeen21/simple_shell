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
	int stat;
	struct stat st;
	

	const char *paths[] = {
	"/bin",
	"/sbin",
	"/usr/bin",
	"/usr/sbin",
	"/usr/local/bin",
	"/usr/local/sbin",
	"/opt/bin",
	"/opt/sbin"
	};

	int i = 0;
	int found = 0;

	while (paths[i] != NULL)
	{
		char *executable_path = malloc(sizeof(char) * (_strlen(paths[i]) + _strlen(args[0]) + 2));
		if (executable_path == NULL)
		{
			perror("nsh");
			return;
		}

		_strcpy(executable_path, paths[i]);
		_strcat(executable_path, "/");
		_strcat(executable_path, args[0]);

		if (stat(executable_path, &st) == 0)
		{
			found = 1;
			args[0] = _strdup(executable_path);
			free(executable_path);
			break;
		}
		free(executable_path);
		i++;
	}

	if (found == 0)
	{
		perror("nsh: command not found");
		free(args[0]);
		free(args);
		return;
	}
   

	child_id = fork();

	if (child_id == -1)
	{
		perror("nsh");
		return;
	}
	if (child_id == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("nsh");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
        do {
		waitpid(child_id, &stat, WUNTRACED);
	} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}

	free(args[0]);
	free(args);
}
