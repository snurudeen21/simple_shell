#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>


int _strlen(char *s);
char *_strdup(char *s);
void my_prompt(void);
char *read_line(void);
char **split_line(char *line);
void _exec(char **args);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void free_buf(char **buf);

struct flags
{
bool interact;
} flags;

#endif /* SHELL_H */
