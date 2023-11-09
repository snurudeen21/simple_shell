#include "shell.h"

/**
* main - execute line, tokens and excecute functions
* 
* Return: 0
*/

int main()
{
    while (true) 
    {
        my_printf("> ");
        char *line = read_line();
        char **tokens = split_line(line);

        if (tokens[0] != NULL) 
        {
            _exec(tokens);
        }

        free(tokens);
        free(line);
    }
    return 0;
}
