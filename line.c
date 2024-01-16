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
	bool is_pipe = false;

	while (true && !is_pipe)
	{
		bytes = getline(&line, &buflen, stdin);

		if (bytes == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		if (bytes == -1)
		{
			perror("Error in getline");
			free(line);
			is_pipe = true;
			break;
		}
		if (line[bytes - 1] == '\n')
		{
			line[bytes - 1] = '\0';
		}
		
		if (_strlen(line) == 0)
		{
			free(line);
			break;
		}

		args = split_line(line);
		_exec(args);
		if (isatty(STDIN_FILENO) != 0)
		{
			break;
		}
	}
	return;
}
