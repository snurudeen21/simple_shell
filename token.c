#include "shell.h"

/**
* split_line - Tokinize command prompt in line into an array
* @line: pointer array to tokenize
*
* Return: containing spilt command prompt
*/

char **split_line(char *line)
{
	int length = 0;
	int bufer = 100;
	char **tokens = malloc(sizeof(char *) * bufer);

	char *delimiters = "\n\t\r";
	char *token = strtok(line, delimiters);

	while (token != NULL)
	{
		tokens[length] = _strdup(token);
		length++;

		token = strtok(NULL, delimiters);
	}

	tokens[length] = NULL;
	return (tokens);
}
