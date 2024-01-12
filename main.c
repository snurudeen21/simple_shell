#include "shell.h"

/**
* main - execute line, tokens and excecute functions
*
* Return: 0
*/

int main(void)
{
	char *line;
	char **tokens;
	bool is_pipe = false;

	while (true && !is_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
		{
			is_pipe = true;
		}
		my_prompt("#cisfun$ ");
		line = read_line();
		if (_strlen(line) == 0)
		{
			free(line);
			continue;
		}
		else
		{
			tokens = split_line(line);
			if (tokens[0] != NULL)
			{
				_exec(tokens);
			}

			free_buf(tokens);
			free(line);
		}
	}
	return (0);
}
