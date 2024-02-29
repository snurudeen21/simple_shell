#include "shell.h"
/**
* path_finder - find path to command in PATH
* @command: command to search in PATH
*
* Return: executable path
*/

char *path_finder(char *command)
{
	struct stat st;
	int i = 0;
  char *executable_path = NULL;

  if (stat(command, &st) == 0)
  {
    executable_path = _strdup(command);
    return (executable_path);
  }

  else
    return (NULL);
}
