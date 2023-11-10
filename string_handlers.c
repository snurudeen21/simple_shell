#include "shell.h"

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

/**
* _strdup - dupicates string from array pointer
* @s: string to be duplicated
*
* Return: pointer to duplicate string
*/
char *_strdup(char *s)
{
	char *ptr;
	int i, len;

	if (s == NULL)
	return (NULL);

	len = _strlen(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
	return (NULL);
	for (i = 0; *s != '\0'; s++, i++)
	ptr[i] = s[0];

	ptr[i++] = '\0';
	return (ptr);
}

/**
* my_prompt - print a string text to stdout
* @prompt: pointer array to text to print
*
* Return: 0
*/

void my_prompt(char *prompt)
{
	write(STDOUT_FILENO, prompt, _strlen(prompt));
}
