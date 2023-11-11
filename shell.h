#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>

int _strlen(char *s);
char *_strdup(char *s);
void my_prompt(char *prompt);
char *read_line(void);
char **split_line(char *line);
void _exec(char **args);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
char *_pathfinder(char *command);

#endif /* SHELL_H */
