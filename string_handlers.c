#include "shell.h"

/**
* my_prompt - print a string text to stdout
* @prompt - pointer array to text to print
*
* Return: 0
*/

void my_prompt(const char *prompt)
{
  write(STDOUT_FILENO, prompt, strlen(prompt));
}

/**
* _strlen - returns the length of a string
* @s: string to be counted
*
* Return: returns length of string passed
*/
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
	count++;
	s++;
	}
	return (count);
}
