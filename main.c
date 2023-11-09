#include "shell.h"

/**
* main - execute line, tokens and excecute functions
*
* Return: 0
*/

int main(void)
{
	while (true)
	{
		char *line = read_line();
		char **tokens = split_line(line);
		line[strcspn(line, "\n")] = '\0';

		if (tokens[0] != NULL)
		{
			_exec(tokens);
		}

		free(tokens);
		free(line);
	}
	return (0);
}
