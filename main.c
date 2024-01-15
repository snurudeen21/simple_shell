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
		else
			my_prompt();
		read_line();
		_exec(tokens);
	}
	return (0);
}
