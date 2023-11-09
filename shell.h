#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int _strlen(char *s);
void my_prompt(char *prompt);
char* read_line();
char** split_line(char *line);
void _exec(char **args);


#endif /* SHELL_H */
