#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

char* kash_read_line();
char** kash_split_line(char *line);
void kash_exec(char **args);


#endif /* SHELL_H */
