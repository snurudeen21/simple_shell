#include "shell_.h"

/**
* _exit - handles the exit command
* @token: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void _exit(char *line, char **token)
{
	free(line);
	free(token);
	exit(0);
}
