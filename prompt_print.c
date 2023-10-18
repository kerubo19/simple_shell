#include "shell.h"

/**
 * show_prompt - Display the prompt.
 */
void show_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 0);
}
