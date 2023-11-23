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
	size_t buflen = 0;
	ssize_t bytes;
	
	while ((bytes = getline(&line, &buflen, stdin) != EOF))
	{
		if (line[bytes - 1] == '\n')
		{
			line[bytes - 1] = '\0';
		}
		my_prompt();
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
