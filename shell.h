#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

int _strlen(char *s);
char *_strdup(char *s);
void my_prompt(char *prompt);
char *read_line(void);
char **split_line(char *line);
void _exec(char **args);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
char *_pathfinder(char *command);
void exit_shell(char *line, char **token);
int _strcmp(char *s1, char *s2);
void print_env(char **env);
void free_buf(char **buf);


#endif /* SHELL_H */
