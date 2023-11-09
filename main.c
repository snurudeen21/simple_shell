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
		my_prompt("#cisfun$ ");
		char *line = read_line();
		line[strcspn(line, "\n")] = '\0';
		char **tokens = split_line(line);
		
		if (tokens[0] != NULL)
		{
			_exec(tokens);
		}

		free(tokens);
		free(line);
	}
	return (0);
}
