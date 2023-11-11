#include "shell.h"
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
