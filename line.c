#include "shell.h"

/**
* line - pointer array to line
* return: line
*/
char* read_line()
{
    char *line = NULL;
    size_t buflen = 0;
    
    getline(&line, &buflen, stdin);
    return line;
}
