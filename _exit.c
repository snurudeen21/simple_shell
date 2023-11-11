#include "shell_.h"

/**
* _exit - handles the exit command
* @token: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void _exit(char **token, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}
