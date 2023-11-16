#include "shell.h"

/**
* exit_shell - handles the exit command
* @token: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void exit_shell(char *line, char **token)
{
	free(line);
	free_buf(token);
	exit(0);
}
