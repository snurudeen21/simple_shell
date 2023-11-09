#include "shell.h"

/**
* split_line - tokinize command prompt into an array
* @line - pointer array to tokenize
*
* Return - Array containing spilt command prompt
*/

char** split_line(char *line)
{
    int length = 0;
    int bufer = 16;
    char **tokens = malloc(sizeof(char*) * bufer);

    char *delimiters = " \t\r\n";
    char *token = strtok(line, delimiters);

    while (token != NULL)
    {
        tokens[length] = token;
        length++;

        if (length >= bufer)
        {
            bufer = (int) (bufer * 1.5);
            tokens = realloc(tokens, bufer * sizeof(char*));
        }

        token = strtok(NULL, delimiters);
    }

    tokens[length] = NULL;
    return tokens;
}
