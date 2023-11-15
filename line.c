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
	ssize_t bytes;

	bytes = getline(&line, &buflen, stdin);
	if (bytes == -1)
	{
		exit(0);
	}
	if (line[bytes - 1] == '\n')
	{
		line[bytes - 1] = '\0';
	}

	return (line);
}
