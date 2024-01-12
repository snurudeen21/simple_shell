#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

void _exec(char **args);
void free_buf(char **buf);
char *read_line(void);
void my_prompt(void);
char **split_line(char *line);
int _strlen(char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
int _strcmp(char *s1, char *s2);


#endif /* SHELL_H */
