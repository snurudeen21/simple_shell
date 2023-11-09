#include "shell.h"

/**
* read_line - read <stdin> using <getline>
*
* Return: line
*/
char *read_line(void)
{
	char *line = NULL;
	size_t buflen = 0;

	getline(&line, &buflen, stdin);
	return (line);
}
