#include "shell.h"
/**
* _pathfinder - find path to command in PATH
* @command: command to append to path in PATH
*
* Return: 0
*/

char *_pathfinder(char *command)
{
	struct stat st;
	
	const char *paths[] = {
		"/bin", "/sbin", "/usr/bin", "/usr/sbin", "/usr/local/bin",
		"/usr/local/sbin", "/opt/bin", "/opt/sbin", NULL
	};
	int i = 0;
	char *executable_path = NULL;

	while (paths[i] != NULL)
	{
		executable_path = malloc(200);
		if (executable_path == NULL)
		{
			perror("nsh");
			return (NULL);
		}
		_strcpy(executable_path, paths[i]);
		_strcat(executable_path, "/");
		_strcat(executable_path, command);

		if (stat(executable_path, &st) == 0)
		{
			break;
		}
		executable_path = NULL;
		i++;
	}

	if (paths[i] == NULL)
	{
		perror("nsh: command not found");
		return (NULL);
	}

	return (executable_path);
}
