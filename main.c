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
		tokens = split_line(line);

		if (_strcmp(tokens[0], "exit") == 0)
		exit_shell(line, tokens);

		if (_strcmp(tokens[0], "env") == 0)
		print_env();

		if (tokens[0] != NULL)
		{
			_exec(tokens);
		}

		free(tokens);
		free(line);
	}
	return (0);
}
