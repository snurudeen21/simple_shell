#include "shell.h"
/**
* my_prompt - print a string text to stdout
*
* Return: 0
*/

void my_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
	flags.interact = 1;
	if (flags.interac)
	write(STDOUT_FILENO, "($) ", 4);
}
