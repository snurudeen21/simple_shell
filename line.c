#include "shell.h"

/**
* read_line - read <stdin> using <getline>
*
* Return: line
*/
void read_line(void)
{
	char *line = NULL;
	char **args;
	size_t buflen = 0;
	ssize_t bytes;

	while ( (bytes = getline(&line, &buflen, stdin)) != EOF)
	{
		/*(if (bytes == EOF)
		{
			exit(0);
		}
		if (bytes == -1)
		{
			perror("Error in getline");
			free(line);
		}*/
		if (line[bytes - 1] == '\n')
		{
			line[bytes - 1] = '\0';
		}
		
		/*if (_strlen(line) == 0)
		{
			free(line);
			continue;
		}*/

		args = split_line(line);
		_exec(args);
	}
	
	return;
}
